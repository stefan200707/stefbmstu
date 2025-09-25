#include <iostream>
using namespace std;
int main() {
    int c = 15;
    int a[c];
    for (int i = 0; i < c; i++) cin >> a[i];
    int max = a[0] - 1, min = a[0] + 1;
    int maxind = -1, minind = -1;
    for (int i = 0; i < c; i++) {
        if (a[i] > max) {
            max = a[i];
            maxind = i;
        }
        if (a[i] < min) {
            min = a[i];
            minind = i;
        }
    }
    if (max == 0 or min == 0) {
        for (int i = 0; i < c; i++) {
            if (i < minind) a[i] = 0;
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}