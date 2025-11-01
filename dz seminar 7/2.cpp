#include <iostream>
#include <cstring>
using namespace std;

void myStrCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
}


int main() {
    char src[100];
    cin.getline(src,100);
    char dest[100];
    myStrCopy(dest,src);
    cout << dest << endl;
    return 0;
}