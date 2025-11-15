#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
using namespace std;

string extractField(const string& line, const string& fieldName) {
    size_t pos = line.find(fieldName);
    if (pos == string::npos) return "";

    pos = line.find(':', pos);
    if (pos == string::npos) return "";
    ++pos; // после двоеточия

    size_t end = line.find(',', pos);
    string val = (end == string::npos) ? line.substr(pos) : line.substr(pos, end - pos);

    size_t start_pos = val.find_first_not_of(" \t");
    if (start_pos == string::npos) return "";
    size_t end_pos = val.find_last_not_of(" \t");
    return val.substr(start_pos, end_pos - start_pos + 1);
}

int parseIntSafe(const string& s) {
    size_t start_pos = s.find_first_not_of(" \t");
    if (start_pos == string::npos) return INT_MAX;
    size_t end_pos = s.find_last_not_of(" \t");
    string t = s.substr(start_pos, end_pos - start_pos + 1);

    if (t.empty()) return INT_MAX;

    try {
        size_t idx = 0;
        int v = stoi(t, &idx);
        if (idx == 0) return INT_MAX;
        return v;
    } catch (...) {
        return INT_MAX;
    }
}

void gg(const string& name) {
    ifstream inFile("tasks.txt");
    if (!inFile.is_open()) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find(name) != string::npos) {
            cout << "Найдена задача: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Задача не найдена." << endl;
}

void srt(int n) {
    ifstream in("tasks.txt");
    vector<string> v;
    string s;

    while (getline(in, s)) v.push_back(s);
    in.close();
    if (v.empty()) return;

    // сортировка по приоритету
    if (n == 1) {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            int pa = parseIntSafe(extractField(a, "Приоритет"));
            int pb = parseIntSafe(extractField(b, "Приоритет"));

            if (pa == pb) return a < b;
            return pa < pb;
        });
    }

    // сортировка по сроку
    else if (n == 2) {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            string da = extractField(a, "Срок");
            string db = extractField(b, "Срок");

            if (da == db) return a < b;
            return da < db;
        });
    }

    ofstream out("tasks.txt");
    for (auto& x : v) out << x << "\n";

    cout << "\nОтсортированные задачи:\n";
    for (auto& x : v) cout << x << "\n";
}


void showByPriority(int maxPriority) {
    ifstream in("tasks.txt");
    if (!in.is_open()) {
        cerr << "Ошибка открытия файла\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        int prValue = parseIntSafe(extractField(line, "Приоритет"));
        if (prValue == INT_MAX) continue; // некорректная строка

        if (prValue <= maxPriority)
            cout << line << endl;
    }
}


void addTask() {
    ofstream outFile("tasks.txt", ios::app);
    string name, priority, deadline;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Название задачи: ";
    getline(cin, name);

    cout << "Приоритет (число): ";
    getline(cin, priority);

    cout << "Срок выполнения: ";
    getline(cin, deadline);

    outFile << "Задача: " << name
            << ", Приоритет: " << priority
            << ", Срок: " << deadline << '\n';
}


int main() {
    while (true) {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 — Добавить задачу\n";
        cout << "2 — Найти задачу по названию\n";
        cout << "3 — Отсортировать (1 — приоритет, 2 — срок)\n";
        cout << "4 — Показать задачи с приоритетом <= X\n";
        cout << "0 — Выход\n";
        cout << "Ваш выбор: ";

        int cmd;
        cin >> cmd;

        if (cmd == 0) break;

        else if (cmd == 1) addTask();

        else if (cmd == 2) {
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите название: ";
            getline(cin, name);
            gg(name);
        }

        else if (cmd == 3) {
            int t;
            cout << "Сортировка: 1 — приоритет, 2 — срок: ";
            cin >> t;
            srt(t);
        }

        else if (cmd == 4) {
            int pr;
            cout << "Введите максимальный приоритет: ";
            cin >> pr;
            showByPriority(pr);
        }

        else cout << "Неверная команда!\n";
    }

    return 0;
}