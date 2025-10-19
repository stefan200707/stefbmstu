#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int maxsize = 100;
    char str[maxsize];
    cin.getline(str,maxsize);
    char t;
    cin >> t;
    char n[maxsize];
    int c = 0;
    for (int i = 0; i < maxsize; i++) {
        if (str[i] != t) {
            n[c] = str[i];
            c++;
        }
        cout << "*" << endl;
    }
    cout << n << endl;
    return 0;
}