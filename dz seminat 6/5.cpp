#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    char alf[] = {"aeiouy"};
    char alf2[] = {"bcdfghjklmnpqrstvwxz"};
    cout << "Введите строку: ";
    cin.getline(str, MAX_SIZE);

    int sogl = 0;
    int gl = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        char* result = strchr(alf,c);
        char* result2 = strchr(alf2,c);
        if (result != nullptr) {
            gl++;
        }
        else if (result2 != nullptr){
            sogl++;
        }
    }
    cout << "gl: " << gl << " sogl: " << sogl << endl;
    return 0;
}