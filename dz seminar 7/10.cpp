#include <iostream>
using namespace std;

void removeSpaces(char* str) {
    char* src = str;
    char* dest = str; 

    while (*src != '\0') {
        if (*src != ' ') {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0'; 
}

int main() {
    char str[1000]; 
    cout << "Введите строку: ";
    cin.getline(str, 1000);

    removeSpaces(str);
    cout << "Строка после удаления пробелов: " << str << endl;

    return 0;
}
