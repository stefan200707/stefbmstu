#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
// Структура для хранения данных о товаре
struct P {
    string s; // Название (string)
    double d;      // Цена (double)
    int i;         // Количество (int)
};

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(2);

    ifstream f("products2.csv");
    if (!f.is_open()) {
        cerr << "Ошибка: products.csv не найден." << endl;
        return 1;
    }

    vector<P> V;
    string l;
    int h = 0;       
    
    int Q = 0;
    double S = 0.0; 
    
    int min_z = 0;   
    int max_z = 0;   

    while (getline(f, l)) {
        if (h++ == 0) continue; 

        stringstream ss(l); 
        string t;           
        P p;

        getline(ss, t, ',');
        p.s = t;

        getline(ss, t, ',');
        try {
            p.d = stod(t);
        } catch (...) { continue; } 

        getline(ss, t, ',');
        try {
            p.i = stoi(t);
        } catch (...) { continue; }

        Q += p.i;
        S += p.d * p.i;

        V.push_back(p);
    }

    cout << "\n--- Список товаров ---" << endl;
    cout << left << setw(30) << "Название"
              << right << setw(10) << "Цена"
              << setw(10) << "Кол-во" << endl;
    cout << string(50, '-') << endl;

    for (size_t i = 0; i < V.size(); ++i) {
        const P& p = V[i];
        cout << left << setw(30) << p.s
                  << right << setw(10) << p.d
                  << setw(10) << p.i << endl;
        
        if (p.d < V[min_z].d) min_z = i;
        if (p.d > V[max_z].d) max_z = i;
    }

    cout << "\n--- Статистика ---" << endl;
    cout << "Общее количество товаров (Q): " << Q << endl;
    cout << "Суммарная стоимость (S): " << S << endl;

    if (!V.empty()) {
        cout << "\nСамый дешевый товар (min_z): " 
                  << V[min_z].s << " (" << V[min_z].d << ")" << endl;
        cout << "Самый дорогой товар (max_z): " 
                  << V[max_z].s << " (" << V[max_z].d << ")" << endl;
    }

    return 0;
}
