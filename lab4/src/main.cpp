#include <iostream>
#include <pqxx/pqxx>

int main() {
    try {
        std::cout << "✅ Библиотека pqxx подключена успешно!" << std::endl;
        std::cout << "Версия libpqxx: " << PQXX_VERSION << std::endl;
        
        // Простая проверка - попытка создать объект соединения
        // Замените строку подключения на свою
        // pqxx::connection conn("dbname=test user=postgres");
        
        std::cout << "Все работает корректно!" << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << "❌ Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}