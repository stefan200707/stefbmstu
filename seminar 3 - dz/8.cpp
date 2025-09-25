#include <iostream>
using namespace std;
int main() {
    int c = 10;
    int a[c];
    for (int i = 0; i < c; i++) cin >> a[i];
    int max = a[0] - 1, min = a[0] + 1, maxi = -1, mini = -1;
    for (int i = 0; i < c; i++) {
        if (a[i] > max) {
            max = a[i];
            maxi = i;
        }
        if (a[i] < min) {
            min = a[i];
            mini = i;
        }
    }
    if (maxi == 2-1 and mini == 5-1) {
        for (int i = 0; i < c; i++) {
            if (i >= maxi and i <= mini) {
                a[i] = max;
            }
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}