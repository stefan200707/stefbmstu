#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct employee {
    string name;
    int age;
    string job;
    int salary;
};

int main() {
    int n;
    cout << "Введите количество добавляемых сотрудников: " << endl;
    cin >> n;
    cin.ignore();

    vector<employee> employers;

    for (int i = 0; i < n; i++) {
        employee k;
        cout << "Введите: ФИО, возраст, должность, зарплата: " << endl;

        cout << "ФИО: ";
        getline(cin, k.name);

        cout << "Возраст: ";
        cin >> k.age;
        cin.ignore();

        cout << "Должность: ";
        getline(cin, k.job);

        cout << "Зарплата: ";
        cin >> k.salary;
        cin.ignore();

        employers.push_back(k);
    }

    ofstream File("Job.txt");
    File << "name,age,job,salary\n";

    int minage = employers[0].age;
    int maxage = employers[0].age;

    employee youngest = employers[0];
    employee oldest  = employers[0];

    double avg = 0;

    for (int i = 0; i < employers.size(); i++) {
        File << employers[i].name << ","
             << employers[i].age << ","
             << employers[i].job << ","
             << employers[i].salary << "\n";

        avg += employers[i].salary;

        if (employers[i].age < minage) {
            minage = employers[i].age;
            youngest = employers[i];
        }

        if (employers[i].age > maxage) {
            maxage = employers[i].age;
            oldest = employers[i];
        }
    }

    avg /= employers.size();

    cout << "Самый молодой сотрудник: "
         << youngest.name << " "
         << youngest.age << " "
         << youngest.job << " "
         << youngest.salary << endl;

    cout << "Самый старший сотрудник: "
         << oldest.name << " "
         << oldest.age << " "
         << oldest.job << " "
         << oldest.salary << endl;

    cout << "Средняя зарплата: " << avg << endl;

    File.close();
    return 0;
}
