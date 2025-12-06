#include <iostream>
#include <vector>
using namespace std;
union Variant {
    int i;
    double d;
    char c;
};
int main() {
    Variant va;
    cout << "Выберите тип данных (i - целое число, d - число с плавающей запятой, c - символ): " << endl;
    char n;
    cin >> n;
    switch (n)
    {
    case 'i':
        cout << "Введите целое число: " << endl;
        cin >> va.i;
        cout << va.i << endl;
        break;
    case 'd':
        cout << "Введите дробное число: " << endl;
        cin >> va.d;
        cout << va.d << endl;
        break;
    case 'c':
        cout << "Введите символ: " << endl;
        cin >> va.c;
        cout << va.c << endl;
        break;
    }
    return 0;
}