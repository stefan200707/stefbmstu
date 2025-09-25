#include <iostream>
using namespace std;
int main() {
    int c = 15;
    double a[c];
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    double maxel = a[0] - 1;
    double minel = a[0] + 1;
    double maxind = -1, minind = -1;
    for (int i = 0; i < c; i++) {
        if (a[i] > maxel) {
            maxel = a[i];
            maxind = i;
        }
        if (a[i] < minel) {
            minel = a[i];
            minind = i;
        }
    }
    if (maxind < minind) {
        cout << (double)maxel * (double)minel << endl;
    }
    return 0;
}