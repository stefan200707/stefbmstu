#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

// Каждый параметр студента — отдельный union
union UName {
    char name[100];
};

union UAge {
    int age;
};

union UAvg {
    double avg;
};

union UId {
    int id;
};

struct Student {
    UName name;
    UAge age;
    UAvg avg;
    UId id;
};

int main() {
    vector<Student> students;

    int n;
    cout << "Введите количество добавляемых студентов: ";
    cin >> n;
    cin.ignore();

    ofstream File("students.txt");
    File << "name,age,avg,id\n";

    // ==== Ввод и запись ====
    for (int i = 0; i < n; i++) {
        cout << "Введите: ФИО, возраст, средний балл, номер зачётки:\n";

        char name_input[100];
        int age_input;
        double avg_input;
        int id_input;

        cin.getline(name_input, 100);
        cin >> age_input;
        cin >> avg_input;
        cin >> id_input;
        cin.ignore();

        Student s;

        strcpy(s.name.name, name_input);
        s.age.age = age_input;
        s.avg.avg = avg_input;
        s.id.id = id_input;

        students.push_back(s);

        File << s.name.name << "," << s.age.age << "," << s.avg.avg << "," << s.id.id << "\n";
    }

    File.close();

    // ==== Чтение обратно ====
    ifstream file("students.txt");
    string line;
    getline(file, line); // пропустить заголовок

    vector<Student> loaded;

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        Student s;

        // name
        getline(ss, temp, ',');
        strcpy(s.name.name, temp.c_str());

        // age
        getline(ss, temp, ',');
        s.age.age = stoi(temp);

        // avg
        getline(ss, temp, ',');
        s.avg.avg = stod(temp);

        // id
        getline(ss, temp, ',');
        s.id.id = stoi(temp);

        loaded.push_back(s);
    }

    // ====== Меню ======
    cout << "\n=== Меню ===\n";
    cout << "1 — вывести всех студентов\n";
    cout << "2 — найти по номеру зачётки\n";
    cout << "3 — вывести со средним баллом выше заданного\n";
    cout << "Введите пункт: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        for (auto &s : loaded) {
            cout << s.name.name << " | возраст: " << s.age.age
                 << " | средний балл: " << s.avg.avg
                 << " | зачётка: " << s.id.id << endl;
        }
    }

    else if (choice == 2) {
        int search_id;
        cout << "Введите номер зачётки: ";
        cin >> search_id;

        bool found = false;

        for (auto &s : loaded) {
            if (s.id.id == search_id) {
                cout << "Найден студент: " << s.name.name << " "
                     << s.age.age << " " << s.avg.avg << " " << s.id.id << endl;
                found = true;
            }
        }

        if (!found) cout << "Студент не найден.\n";
    }

    else if (choice == 3) {
        double min_avg;
        cout << "Введите минимальный средний балл: ";
        cin >> min_avg;

        bool found = false;

        for (auto &s : loaded) {
            if (s.avg.avg > min_avg) {
                cout << s.name.name << " — " << s.avg.avg << endl;
                found = true;
            }
        }

        if (!found) cout << "Нет студентов с таким баллом.\n";
    }

    return 0;
}
