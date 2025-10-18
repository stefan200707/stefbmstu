#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    char str2[MAX_SIZE];
    cout << "Введите строку A: ";
    cin.getline(str, MAX_SIZE);
    cout << "Введите строку B: ";
    cin.getline(str2, MAX_SIZE);
    int lim;
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
    int f = 0;
    for (int i = 0; i < strlen(srav); i++) {
        char c = srav[i];
        char* result = strchr(str2,c);
        if (result == nullptr) {
            f = 1;
        }
    }
    if (!f) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}