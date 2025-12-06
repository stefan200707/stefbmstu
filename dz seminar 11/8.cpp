#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct P {
    std::string s; // Название
    double d;      // Цена
    int i;         // Количество
    std::string c; // Категория
};

// Функция для записи в CSV
void W(const std::string& N, const std::vector<P>& V) {
    std::ofstream o(N);
    o << "Название,Цена,Количество,Категория\n";
    for (const auto& p : V) {
        o << p.s << "," << p.d << "," << p.i << "," << p.c << "\n";
    }
}

int main() {
    std::ifstream f("products.csv");
    if (!f.is_open()) {
        std::cerr << "Ошибка: products.csv не найден." << std::endl;
        return 1;
    }

    std::vector<P> V; // Исходный вектор
    std::string l;
    int h = 0;

    // 1. Чтение данных
    while (std::getline(f, l)) {
        if (h++ == 0) continue; 

        std::stringstream ss(l);
        std::string t;
        P p;

        try {
            std::getline(ss, t, ','); p.s = t;
            std::getline(ss, t, ','); p.d = std::stod(t);
            std::getline(ss, t, ','); p.i = std::stoi(t);
            std::getline(ss, t, ','); p.c = t;
            V.push_back(p);
        } catch (...) {
            // Игнорируем некорректные строки
        }
    }
    f.close();

    std::cout << "Загружено: " << V.size() << " товаров." << std::endl;
    
    // 2. Определение лямбда-фильтров
    
    // Лямбда 1: Цена выше 500.00
    auto L1 = [](const P& p) { return p.d > 500.00; };
    
    // Лямбда 2: Категория "Электроника"
    auto L2 = [](const P& p) { return p.c == "Электроника"; };
    
    // Лямбда 3: Количество больше 10
    auto L3 = [](const P& p) { return p.i > 10; };

    // 3. Применение фильтров с использованием copy_if
    
    // Фильтр 1: Дороже 500
    std::vector<P> V1;
    std::copy_if(V.begin(), V.end(), std::back_inserter(V1), L1);
    std::cout << "\nФильтр 1 (Цена > 500): " << V1.size() << " товаров." << std::endl;
    W("filtered_expensive.csv", V1);

    // Фильтр 2: Электроника
    std::vector<P> V2;
    std::copy_if(V.begin(), V.end(), std::back_inserter(V2), L2);
    std::cout << "Фильтр 2 (Электроника): " << V2.size() << " товаров." << std::endl;
    W("filtered_electronics.csv", V2);
    
    // Фильтр 3: Количество > 10
    std::vector<P> V3;
    std::copy_if(V.begin(), V.end(), std::back_inserter(V3), L3);
    std::cout << "Фильтр 3 (Кол-во > 10): " << V3.size() << " товаров." << std::endl;
    W("filtered_stock.csv", V3);

    
    // Создаем копию для демонстрации, чтобы не портить исходный вектор V
    std::vector<P> V_copy = V; 
    
    // Лямбда для remove_if:
    // Мы хотим оставить товары с Категорией "Периферия".
    // remove_if удаляет элементы, для которых лямбда возвращает TRUE.
    auto L_remove = [](const P& p) { return p.c != "Периферия"; }; 

    // remove_if перемещает элементы, которые нужно удалить, в конец
    auto new_end = std::remove_if(V_copy.begin(), V_copy.end(), L_remove);
    
    // erase физически удаляет эти элементы из вектора
    V_copy.erase(new_end, V_copy.end());

    std::cout << "\nДемонстрация remove_if/erase (Осталась только Периферия): " 
              << V_copy.size() << " товаров." << std::endl;
    W("filtered_periphery_inplace.csv", V_copy);

    return 0;
}
