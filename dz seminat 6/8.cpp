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
    int f = 0;
    str[0] = toupper(str[0]);
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '!' or c == '.' or c == '?') {
            f = 1; 
        }
        if (f == 1 and isalpha(c)) {
            str[i] = toupper(str[i]);
            f = 0;
        }
    }
    cout << str << endl;
    return 0;
}