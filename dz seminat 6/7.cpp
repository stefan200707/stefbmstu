#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    
    cout << "Введите строку: ";
    cin.getline(str, MAX_SIZE);
    int i = 0;
    int k = 1;
    while (true) {
        if (i < strlen(str)) {
            if (str[i+1] == str[i]) {
                k++;
            }
            else {
                cout << str[i] << k;
                k = 1;
            }
        }
        else {
            break;
        }
        i++;
    }
    cout << endl;

    return 0;
}