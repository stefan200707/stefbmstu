#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <numeric>
#include <string>  
#include <iomanip>  // для setprecision
using namespace std;

int main() {
    map<string, vector<double>> sensorData;
    ifstream read("power_log.txt");
    
    // Проверка открытия файла
    if (!read.is_open()) {
        cerr << "Ошибка: не удалось открыть файл power_log.txt" << endl;
        return 1;
    }
    
    string line;
    
    while (getline(read, line)) {
        stringstream ss(line);
        string first, second;
        double number;
        
        ss >> first >> second;
        
        while (ss >> number) {
            sensorData[second].push_back(number);
        }
    }
    
    // Устанавливаем точность вывода чисел
    cout << fixed << setprecision(2);
    
    for (const auto& sensor : sensorData) {
        const vector<double>& values = sensor.second;
        
        if (!values.empty()) {
            auto min_val = *min_element(values.begin(), values.end());
            auto max_val = *max_element(values.begin(), values.end());
            double sum = accumulate(values.begin(), values.end(), 0.0);
            double average = sum / values.size();
            
            cout << "Датчик: " << sensor.first << endl;
            cout << "  Сумма: " << sum << endl;
            cout << "  Среднее: " << average << endl;
            cout << "  Количество: " << values.size() << endl;
            cout << "  Мин: " << min_val << endl;
            cout << "  Макс: " << max_val << endl;
            cout << endl;
        }
    }
    
    return 0;
}