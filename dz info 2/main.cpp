#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

// Функция для разделения строки CSV
vector<string> splitCSVLine(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string item;

    while (getline(ss, item, ',')) {
        // Удаляем возможные кавычки
        if (!item.empty() && item.front() == '"' && item.back() == '"') {
            item = item.substr(1, item.size() - 2);
        }
        result.push_back(item);
    }
    return result;
}

// Функция для загрузки данных из CSV файла
vector<vector<string>> loadCSVData(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла " << filename << endl;
        return data;
    }

    string line;
    // Пропускаем заголовок (если есть)
    getline(file, line);

    while (getline(file, line)) {
        data.push_back(splitCSVLine(line));
    }

    file.close();
    return data;
}
pqxx::connection connect() {
    return pqxx::connection{"host=localhost port=5432 dbname=postgres user=stefanrozkov password=stef4587"};
}

int main() {
    try {
        // 1. Подключение к базе данных
        // Замените параметры подключения на реальные
        pqxx::connection conn = connect();

        if (conn.is_open()) {
            cout << "Успешное подключение к базе данных: " << conn.dbname() << endl;
        } else {
            cerr << "Ошибка подключения к базе данных" << endl;
            return 1;
        }

        // 2. Загрузка данных из CSV файлов
        vector<vector<string>> salesData = loadCSVData("sales.csv");
        vector<vector<string>> productsData = loadCSVData("products.csv");
        vector<vector<string>> customersData = loadCSVData("customers.csv");

        // 3. Создание таблиц
        work tx(conn);

        tx.exec("DROP TABLE IF EXISTS sales_fact CASCADE;");
        tx.exec("DROP TABLE IF EXISTS products_dim CASCADE;");
        tx.exec("DROP TABLE IF EXISTS customers_dim CASCADE;");

        tx.exec("CREATE TABLE products_dim ("
                "product_id INT PRIMARY KEY, "
                "product_name VARCHAR(255), "
                "category VARCHAR(255), "
                "price DECIMAL(10,2));");

        tx.exec("CREATE TABLE customers_dim ("
                "customer_id INT PRIMARY KEY, "
                "customer_name VARCHAR(255), "
                "region VARCHAR(255));");

        tx.exec("CREATE TABLE sales_fact ("
                "sale_id SERIAL PRIMARY KEY, "
                "sale_date DATE, "
                "product_id INT REFERENCES products_dim(product_id), "
                "customer_id INT REFERENCES customers_dim(customer_id), "
                "quantity INT, "
                "amount DECIMAL(10,2));");

        tx.commit();
        cout << "Таблицы успешно созданы" << endl;

        // 4. Загрузка данных в таблицы
        // Загрузка продуктов
        work tx_products(conn);
        for (const auto& row : productsData) {
            if (row.size() >= 4) {
                tx_products.exec_prepared(
                    "insert_product",
                    row[0], // product_id
                    row[1], // product_name
                    row[2], // category
                    row[3]  // price
                );
            }
        }
        tx_products.commit();
        cout << "Данные продуктов загружены: " << productsData.size() << " записей" << endl;

        // Подготовка запроса для продуктов
        conn.prepare("insert_product",
            "INSERT INTO products_dim (product_id, product_name, category, price) "
            "VALUES ($1, $2, $3, $4)");

        // Загрузка клиентов
        work tx_customers(conn);
        for (const auto& row : customersData) {
            if (row.size() >= 3) {
                tx_customers.exec_prepared(
                    "insert_customer",
                    row[0], // customer_id
                    row[1], // customer_name
                    row[2]  // region
                );
            }
        }
        tx_customers.commit();
        cout << "Данные клиентов загружены: " << customersData.size() << " записей" << endl;

        // Подготовка запроса для клиентов
        conn.prepare("insert_customer",
            "INSERT INTO customers_dim (customer_id, customer_name, region) "
            "VALUES ($1, $2, $3)");

        // Загрузка продаж
        work tx_sales(conn);
        for (const auto& row : salesData) {
            if (row.size() >= 6) {
                tx_sales.exec_prepared(
                    "insert_sale",
                    row[0], // sale_date
                    row[1], // product_id
                    row[2], // customer_id
                    row[3], // quantity
                    row[4]  // amount
                );
            }
        }
        tx_sales.commit();
        cout << "Данные продаж загружены: " << salesData.size() << " записей" << endl;

        // Подготовка запроса для продаж
        conn.prepare("insert_sale",
            "INSERT INTO sales_fact (sale_date, product_id, customer_id, quantity, amount) "
            "VALUES ($1, $2, $3, $4, $5)");

        // 5. Аналитические запросы
        cout << "\n=== АНАЛИТИЧЕСКИЕ ЗАПРОСЫ ===" << endl;

        // Объем продаж по категориям
        cout << "\n1. Объем продаж по категориям (топ-5):" << endl;
        work tx_query1(conn);
        result sales_by_category = tx_query1.exec(
            "SELECT p.category, SUM(s.amount) AS total_sales "
            "FROM sales_fact s "
            "JOIN products_dim p ON s.product_id = p.product_id "
            "GROUP BY p.category "
            "ORDER BY total_sales DESC "
            "LIMIT 5"
        );

        for (const auto& row : sales_by_category) {
            cout << "  " << row["category"].c_str() << ": "
                 << row["total_sales"].c_str() << endl;
        }
        tx_query1.commit();

        // Количество покупок по регионам
        cout << "\n2. Количество покупок по регионам (топ-5):" << endl;
        work tx_query2(conn);
        result sales_by_region = tx_query2.exec(
            "SELECT c.region, COUNT(s.sale_id) AS number_of_sales "
            "FROM sales_fact s "
            "JOIN customers_dim c ON s.customer_id = c.customer_id "
            "GROUP BY c.region "
            "ORDER BY number_of_sales DESC "
            "LIMIT 5"
        );

        for (const auto& row : sales_by_region) {
            cout << "  " << row["region"].c_str() << ": "
                 << row["number_of_sales"].c_str() << " покупок" << endl;
        }
        tx_query2.commit();

        // Средний чек по регионам
        cout << "\n3. Средний чек по регионам:" << endl;
        work tx_query3(conn);
        result avg_check_by_region = tx_query3.exec(
            "SELECT c.region, AVG(s.amount) AS avg_check "
            "FROM sales_fact s "
            "JOIN customers_dim c ON s.customer_id = c.customer_id "
            "GROUP BY c.region "
            "ORDER BY avg_check DESC"
        );

        for (const auto& row : avg_check_by_region) {
            cout << "  " << row["region"].c_str() << ": "
                 << row["avg_check"].c_str() << endl;
        }
        tx_query3.commit();

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    cout << "\nПрограмма успешно завершена!" << endl;
    return 0;
}