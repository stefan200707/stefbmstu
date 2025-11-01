#include <iostream>
#include <cstring>
using namespace std;

void myStr(char* src) {
    int count = 0;
    while (*src) {
        if (*src == ' ') {
            *src = '_';
        }
        src++;
    }
}


int main() {
    char src[100];
    cin.getline(src,100);
    myStr(src);
    cout << src << endl;
    return 0;
}