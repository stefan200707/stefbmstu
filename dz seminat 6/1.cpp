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

    int left = 0;
    int right = strlen(str) - 1;
    int f = 0;
    
    while (left < right) {
        while (left < right && isspace(str[left])) {
            left++;
        }
        while (left < right && isspace(str[right])) {
            right--;
        }
        
        if (tolower(str[left]) != tolower(str[right])) {
            f = 1;
        }
        
        left++;
        right--;
    }
    
    if (!f) {
        cout << "Палиндром" << endl;
    } else {
        cout << "Не палиндром" << endl;
    }
    
    return 0;
}