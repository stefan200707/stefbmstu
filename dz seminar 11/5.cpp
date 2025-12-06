#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main() {
    Student students[] = {
        {1, "Иван Петров", 20, 4.5},
        {2, "Мария Сидорова", 19, 4.8},
        {3, "Алексей Иванов", 21, 4.2}
    };

    ofstream outFile("students.dat", ios::binary);
    for (int i = 0; i < 3; i++) {
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outFile.close();

    ifstream inFile("students.dat", ios::binary);
    vector<Student> studentList;
    Student temp;

    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        studentList.push_back(temp);
    }
    inFile.close();

    // Вывод всех студентов
    cout << "Список всех студентов:" << endl;
    for (const auto& s : studentList) {
        cout << "ID: " << s.id << ", Имя: " << s.name 
             << ", Возраст: " << s.age << ", Средний балл: " << s.average_grade << endl;
    }

    // Поиск студента с максимальным баллом
    Student bestStudent = studentList[0];
    for (const auto& s : studentList) {
        if (s.average_grade > bestStudent.average_grade) {
            bestStudent = s;
        }
    }
    cout << "\nСтудент с наивысшим баллом:" << endl;
    cout << "ID: " << bestStudent.id << ", Имя: " << bestStudent.name 
         << ", Средний балл: " << bestStudent.average_grade << endl;

    cout << "\nОбщее количество студентов: " << studentList.size() << endl;

    return 0;
}