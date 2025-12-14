#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

// ---------------- CSV utils ----------------
vector<string> splitCSVLine(const string& line, char delimiter = ',') {
    vector<string> result;
    string item;
    bool inQuotes = false;
    string current;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == delimiter && !inQuotes) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    result.push_back(current);

    // убрать кавычки
    for (auto& s : result) {
        if (!s.empty() && s.front() == '"' && s.back() == '"') {
            s = s.substr(1, s.size() - 2);
        }
    }
    return result;
}

vector<vector<string>> loadCSVData(const string& filename, char delimiter = ',') {
    vector<vector<string>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла: " << filename << endl;
        return data;
    }

    string line;
    getline(file, line); // пропускаем заголовок

    while (getline(file, line)) {
        if (!line.empty())
            data.push_back(splitCSVLine(line, delimiter));
    }

    file.close();
    return data;
}

// ---------------- DB utils ----------------
connection connect_db() {
    return connection{
        "host=localhost port=5432 dbname=stefbmstu_db user=stefanrozkov password=stef4587"
    };
}

int main() {
    try {
        // ---------------- connect ----------------
        connection conn = connect_db();
        if (!conn.is_open()) {
            cerr << "Не удалось подключиться к БД" << endl;
            return 1;
        }
        cout << "Подключение к БД успешно" << endl;

        // ---------------- load CSV ----------------
        auto productsData  = loadCSVData("products.csv");
        auto customersData = loadCSVData("customers.csv");
        auto salesData     = loadCSVData("sales.csv");

        if (productsData.empty() || customersData.empty() || salesData.empty()) {
            cerr << "Один или несколько CSV файлов пусты или не загружены" << endl;
            return 1;
        }

        // ---------------- create tables ----------------
        {
            work tx(conn);
            tx.exec("DROP TABLE IF EXISTS sales_fact CASCADE");
            tx.exec("DROP TABLE IF EXISTS products_dim CASCADE");
            tx.exec("DROP TABLE IF EXISTS customers_dim CASCADE");

            tx.exec(
                "CREATE TABLE products_dim("
                "product_id INT PRIMARY KEY,"
                "product_name TEXT,"
                "category TEXT,"
                "price NUMERIC(10,2))");

            tx.exec(
                "CREATE TABLE customers_dim("
                "customer_id INT PRIMARY KEY,"
                "customer_name TEXT,"
                "region TEXT)");

            tx.exec(
                "CREATE TABLE sales_fact("
                "sale_id SERIAL PRIMARY KEY,"
                "sale_date DATE,"
                "product_id INT REFERENCES products_dim(product_id),"
                "customer_id INT REFERENCES customers_dim(customer_id),"
                "quantity INT,"
                "amount NUMERIC(10,2))");

            tx.commit();
            cout << "Таблицы созданы" << endl;
        }

        // ---------------- prepare queries (ТЕПЕРЬ ПОСЛЕ СОЗДАНИЯ ТАБЛИЦ) ----------------
        conn.prepare("insert_product",
            "INSERT INTO products_dim (product_id, product_name, category, price) "
            "VALUES ($1,$2,$3,$4)");

        conn.prepare("insert_customer",
            "INSERT INTO customers_dim (customer_id, customer_name, region) "
            "VALUES ($1,$2,$3)");

        conn.prepare("insert_sale",
            "INSERT INTO sales_fact (sale_date, product_id, customer_id, quantity, amount) "
            "VALUES ($1,$2,$3,$4,$5)");

        cout << "Подготовленные запросы созданы" << endl;

        // ---------------- insert products ----------------
        {
            work tx(conn);
            for (const auto& r : productsData) {
                if (r.size() == 4)
                    tx.exec_prepared("insert_product", r[0], r[1], r[2], r[3]);
            }
            tx.commit();
        }
        cout << "Продукты загружены (" << productsData.size() << " записей)" << endl;

        // ---------------- insert customers ----------------
        {
            work tx(conn);
            for (const auto& r : customersData) {
                if (r.size() == 3)
                    tx.exec_prepared("insert_customer", r[0], r[1], r[2]);
            }
            tx.commit();
        }
        cout << "Клиенты загружены (" << customersData.size() << " записей)" << endl;

        // ---------------- insert sales ----------------
        {
            work tx(conn);
            for (const auto& r : salesData) {
                if (r.size() >= 6) {  // sales.csv имеет 6 полей
                    // Используем поля: sale_date, product_id, customer_id, quantity, amount
                    // Пропускаем sale_id (поле 0)
                    tx.exec_prepared("insert_sale", r[1], r[2], r[3], r[4], r[5]);
                }
            }
            tx.commit();
        }
        cout << "Продажи загружены (" << salesData.size() << " записей)" << endl;

        // ---------------- analytics ----------------
        cout << "\nТОП категорий по продажам:\n";
        {
            work tx(conn);
            auto res = tx.exec(
                "SELECT p.category, SUM(s.amount) total "
                "FROM sales_fact s JOIN products_dim p ON s.product_id=p.product_id "
                "GROUP BY p.category ORDER BY total DESC LIMIT 5");
            for (auto row : res)
                cout << row[0] << " : " << row[1] << endl;
        }

        cout << "\nПрограмма завершена успешно" << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}