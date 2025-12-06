#include <iostream>
#include <string>
using namespace std;

union DateTime {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
};

int main() {
    DateTime neo;
    string s;
    cout << "Введите год: " << endl;
    cin >> neo.year;
    s = to_string(neo.year) + "-";
    cout << "Введите месяц: " << endl;
    cin >> neo.month;
    s += to_string(neo.month) + "-";
    cout << "Введите день: " << endl;
    cin >> neo.day;
    s += to_string(neo.day) + " ";
    cout << "Введите час: " << endl;
    cin >> neo.hour;
    s += to_string(neo.hour) + ":";
    cout << "Введите минуту: " << endl;
    cin >> neo.min;
    s += to_string(neo.min) + ":";
    cout << "Введите секунду: " << endl;
    cin >> neo.sec;
    s += to_string(neo.sec);
    cout << s << endl;
    return 0;
}