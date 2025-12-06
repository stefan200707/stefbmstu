#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void createConfig() {
    ofstream file("config.json");
    file << "{\n";
    file << " \"app_name\": \"My Application\",\n";
    file << " \"version\": \"1.0.0\",\n";
    file << " \"settings\": {\n";
    file << " \"max_connections\": 100,\n";
    file << " \"timeout\": 30,\n";
    file << " \"debug_mode\": true\n";
    file << " },\n";
    file << " \"database\": {\n";
    file << " \"host\": \"localhost\",\n";
    file << " \"port\": 5432,\n";
    file << " \"username\": \"admin\"\n";
    file << " }\n";
    file << "}";
    file.close();
    cout << "Конфигурационный файл создан\n";
}

int main() {
    createConfig();
    
    ifstream file("config.json");
    cout << "type parameter you want to change: " << endl;
    string key;
    getline(cin, key);
    
    cout << "type new parameter value: " << endl;
    string newValue;
    getline(cin, newValue);
    
    vector<string> lines;
    string line;
    bool found = false;
    
    while (getline(file, line)) {
        // Используем stringstream для анализа каждой строки
        stringstream ss(line);
        string token;
        
        // Разбиваем строку на части
        vector<string> parts;
        while (getline(ss, token, ':')) {
            parts.push_back(token);
        }
        
        // Проверяем, есть ли ключ в первой части
        if (parts.size() > 0) {
            // Ищем ключ в кавычках
            if (parts[0].find("\"" + key + "\"") != string::npos) {
                found = true;
                
                // Строим новую строку с новым значением
                line = parts[0] + ": ";
                
                // Добавляем значение с правильным форматированием
                if (isdigit(newValue[0]) || newValue == "true" || newValue == "false") {
                    line += newValue;
                } else {
                    line += "\"" + newValue + "\"";
                }
                
                // Добавляем запятую, если она была
                if (parts.size() > 1 && !parts[1].empty() && parts[1].back() == ',') {
                    line += ",";
                }
            }
        }
        lines.push_back(line);
    }
    file.close();
    
    if (found) {
        // Записываем изменения
        ofstream outFile("config.json");
        for (const auto& l : lines) {
            outFile << l << endl;
        }
        outFile.close();
        cout << "Successfully changed!" << endl;
    } else {
        cout << "Parameter not found!" << endl;
    }
    
    return 0;
}