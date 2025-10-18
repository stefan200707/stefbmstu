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
    char srav[MAX_SIZE];
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        char* result = strchr(srav,c);
        if (result == nullptr) {
            srav[t] = c;
            t++;

        }
    }
    srav[t] = '\0';
    cout << strlen(srav) << " " << srav << endl;
    return 0;
}