#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int maxsize = 100;
    char str[maxsize];
    cin.getline(str,maxsize);
    const char* deliv = " \t\n";
    char* word = strtok(str,deliv);
    if (word == nullptr) {
        cout << "Нет слов.\n";
        return 0;
    }
    int maxlen = -1;
    char* w[maxsize];
    while (word != nullptr) {
        int len = strlen(word);
        if (len > maxlen) {
            maxlen = len;
            *w = word;
        }
        word = strtok(nullptr,deliv);
    }
    cout << *w << endl;
    return 0;
}