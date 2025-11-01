#include <iostream>
#include <cstring>
using namespace std;

int myStrLen(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}


int main() {
    char str[100];
    cin.getline(str,100);
    cout << myStrLen(str) << endl;
    return 0;
} 