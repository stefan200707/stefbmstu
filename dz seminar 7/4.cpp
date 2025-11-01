#include <iostream>
#include <cstring>
using namespace std;

int myStrCount(const char* src, char c) {
    int count = 0;
    while (*src) {
        if (*src == c) {
            count++;
        }
        src++;
    }
    return count;
}


int main() {
    char src[100];
    cin.getline(src,100);
    char c;
    cin >> c;
    cout << myStrCount(src, c) << endl;
    return 0;
}