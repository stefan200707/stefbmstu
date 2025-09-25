#include <iostream>
using namespace std;
int main() {
    int c = 10;
    int mmi = 5;
    int mma = 10;
    int a[c];
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    int maxel = a[0] - 1;
    int minel = a[0] + 1;
    int maxi = -1;
    int mini = -1;
    for (int i = 0; i < c; i++) {
        if (a[i] > maxel) {
            maxel = a[i];
            maxi = i;
        }
        if (a[i] < minel) {
            minel = a[i];
            mini = i;
        }
    }
    if ((mini == mmi - 1) and (maxi == mma - 1)) cout << (maxel + minel) / 2. << endl;
    return 0;
}