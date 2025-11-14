#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------------- Поиск задачи ----------------------
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
            cout << "задача: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Задача не найдена." << endl;
}


// ---------------------- Сортировка ----------------------
void srt(int n) {
    ifstream in("tasks.txt");
    vector<string> v;
    string s;

    while (getline(in, s)) v.push_back(s);
    in.close();
    if (v.empty()) return;

    if (n == 1) {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            size_t pa = a.find("Приоритет: ") + 12;
            size_t enda = a.find(",", pa);
            int priA = stoi(a.substr(pa, enda - pa));

            size_t pb = b.find("Приоритет: ") + 12;
            size_t endb = b.find(",", pb);
            int priB = stoi(b.substr(pb, endb - pb));

            return priA < priB;
        });
    }

    else if (n == 2) {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            size_t pa = a.find("Срок: ") + 6;
            string da = a.substr(pa);

            size_t pb = b.find("Срок: ") + 6;
            string db = b.substr(pb);

            return da < db; 
        });
    }

    ofstream out("tasks.txt");
    for (auto& x : v) out << x << "\n";
}


// ---------------------- Вывод по приоритету ----------------------
void showByPriority(int maxPriority) {
    ifstream in("tasks.txt");
    if (!in.is_open()) {
        cerr << "Ошибка открытия файла\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        size_t p = line.find("Приоритет: ");
        if (p == string::npos) continue;

        string pr = line.substr(p + 12);  
        size_t comma = pr.find(',');
        if (comma != string::npos) pr = pr.substr(0, comma);

        int prValue = stoi(pr);

        if (prValue <= maxPriority)
            cout << line << endl;
    }
}


// ---------------------- Добавление задачи ----------------------
void addTask() {
    ofstream outFile("tasks.txt", ios::app);
    string name, priority, deadline;

    cout << "Название задачи: ";
    cin.ignore();
    getline(cin, name);

    cout << "Приоритет (число): ";
    getline(cin, priority);

    cout << "Срок выполнения: ";
    getline(cin, deadline);

    outFile << "Задача: " << name
            << ", Приоритет: " << priority
            << ", Срок: " << deadline << '\n';
}


// ---------------------- МЕНЮ ----------------------
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
            cout << "Введите название: ";
            cin.ignore();
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
