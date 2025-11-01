#include <iostream>
#include <cstring>
using namespace std;

int findSubstring(const char* s, const char* word) 
{
    int wlen = strlen(word);
    int k = 0;

    for (const char* p = s; p < s + strlen(s) - wlen; p++) {
        int match = 1;
        for (int i = 0; i < wlen; i++) {
            if (*(p + i) != word[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return (int)(p - s);
        }
    }

    return 0;
}

int main()
{
    char src[100];
    cin.getline(src, 100);
    char word[100];
    cin.getline(word, 100);

    int result = findSubstring(src, word);
    if (result) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
