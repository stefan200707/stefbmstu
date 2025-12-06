#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct student {
    string name;
    int age;
    double avg;
    int id;
};

int main() {
    int n;
    cout << "Введите количество добавляемых студентов" << endl;
    cin >> n;
    cin.ignore();
    vector<student> students;
    for (int i = 0; i < n; i++) {
        student k;
        cout << "Введите: ФИО, возраст, средний балл, номер зачётки: " << endl;
        string name;
        int age;
        double avg;
        int id;
        getline(cin,name);
        cin >> k.age;
        cin >> k.avg;
        cin >> k.id;
        cin.ignore();
        k.name = name;
        
        students.push_back(k);
    }
    ofstream File("students.txt");
    string line = "name,age,avg,id";
    File << line << "\n";
    for (int i = 0; i < students.size(); i++) {
        File << students[i].name << "," << students[i].age << "," << students[i].avg << "," << students[i].id << "\n";
    }
    File.close();
    return 0;
}