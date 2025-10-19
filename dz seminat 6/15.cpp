#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    cout << "Введите строку 1: ";
    cin.getline(str, MAX_SIZE);
    int len1 = 0;
    len1 = strlen(str);
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

    int len2 = 0;
    char str2[MAX_SIZE];
    cout << "Введите строку 2: ";
    cin.getline(str2, MAX_SIZE);
    len2 = strlen(str2);
    int q = 0; 
    char srav2[MAX_SIZE];
    for (int i = 0; str2[i] != '\0'; i++) {
        char c = str2[i];
        char* result = strchr(srav2,c);
        if (result == nullptr) {
            srav2[q] = c;
            q++;
        }
    }
    srav2[q] = '\0';
    int k = 0;
    for (int i = 0; i < strlen(srav2); i++) {
        if (strchr(srav,srav2[i]) != nullptr) {
            k++;
        }
    }
    if ((len1 == len2) and (k == strlen(srav2))) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}