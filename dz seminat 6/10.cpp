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
    int k = 0;
    char strnew[MAX_SIZE];

    for (int i = 0; i < strlen(str); i++) {
        char temp[MAX_SIZE];
        int in = 0;
        
        while (str[i] != ' ' && str[i] != '\0') {
            temp[in] = str[i];
            in++;
            i++;
        }
        temp[in] = '\0';
        reverse(temp, temp + strlen(temp));
        for (int j = 0; j < strlen(temp); j++) {
            strnew[k] = temp[j];
            k++;
        }

    }
    cout << strnew << endl;
    return 0;
}