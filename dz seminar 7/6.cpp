#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *s)
{
    size_t len = strlen(s);
    char *front = s;
    char *back  = s + len - 1;

    while (front <= back) {
        if (front != back) {
            char tmp = *front;
            *front = *back;
            *back  = tmp;
        }
        ++front;
        --back;
    }
}

int main()
{
    char src[100];
    cin.getline(src, 100);  

    reverse(src);

    cout << src << '\n';
    return 0;
}
