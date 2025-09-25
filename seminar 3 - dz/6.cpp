#include <iostream>
using namespace std;
int main() {
    int c = 15;
    double a[c];
    for (int i = 0; i < c; i++) cin >> a[i];
    double max = a[0] - 1;
    double min = a[0] - 1;
    double minind = -1, maxind = -1;
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
    cout << max << " " << maxind << " " << min << " " << minind << endl;
    if (minind == 1 and maxind == 0) {
        for (int i = 0; i < c; i++) {
            a[i] /= 2.;
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}