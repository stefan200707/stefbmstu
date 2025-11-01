#include <iostream>
#include <cstring>
using namespace std;

void myStrCat(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    dest[i] = ' ';
    i++;
    dest[i] = ' ';
    int c = 0;
    for (int t = i+0; t < i + strlen(src); t++) {
        dest[t] = src[t-i];
        c = t;
    }
    dest[c+1] = '\0';
}


int main() {
    char src[100];
    cin.getline(src,100);
    char dest[100];
    cin.getline(dest,100);
    myStrCat(dest,src);
    cout << dest << endl;
    return 0;
}