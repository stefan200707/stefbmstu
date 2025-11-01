#include <iostream>
#include <cstring>
using namespace std;

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2) {
            return -1;
        } else if (*s1 > *s2) {
            return 1;
        }
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0') {
        return 0; 
    } else if (*s1 == '\0') {
        return -1; // s1 короче s2
    } else {
        return 1; // s1 длиннее s2
    }
}


int main()
{
    char src[100];
    cin.getline(src, 100);
    char scr2[100];
    cin.getline(scr2,100);
    if (myStrCmp(src,scr2)==0){
        cout << "Строки равны" << endl;
    }
    else if (myStrCmp(src,scr2)==-1){
        cout << "первая строка меньше второй" << endl;
    }
    else {
        cout << "первая строка больше второй" << endl;
    }    return 0;
}
