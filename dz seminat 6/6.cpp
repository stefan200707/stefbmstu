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
    int t = 0; 
    cin >> t;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (isupper(c)) {
            c = (int(str[i]) - int('A') + t) % 26 + int('A');
            str[i] = char(c); 
        }
        else if (islower(c)){
            c = (int(str[i]) - int('a') + t) % 26 + int('a');
            str[i] = char(c); 
        }
    }
    cout << str << endl;
    return 0;
}