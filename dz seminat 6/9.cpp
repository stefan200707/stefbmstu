#include <iostream>
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
    
    int max_len = 0;
    char longest_common[MAX_SIZE] = "";
    
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str[i] == str2[j]) {
                int len = 0;
                while (str[i + len] == str2[j + len] && 
                       str[i + len] != '\0' && 
                       str2[j + len] != '\0') {
                    len++;
                }
                
                if (len > max_len) {
                    max_len = len;
                    strncpy(longest_common, &str[i], len);
                    longest_common[len] = '\0';
                }
            }
        }
    }
    
    if (max_len > 0) {
        cout << longest_common << endl;
    }
    
    return 0;
}