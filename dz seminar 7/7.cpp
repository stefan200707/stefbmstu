#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrom(const char *s)
{
    size_t len = strlen(s);
    const char *front = s;
    const char *back  = s + len - 1;

    while (front < back) {
        if (*front != *back) {
            return false;
        }
        ++front;
        --back;
    }
    return true;
}

int main()
{
    char src[100];
    cin.getline(src, 100);
    if (isPalindrom(src)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
