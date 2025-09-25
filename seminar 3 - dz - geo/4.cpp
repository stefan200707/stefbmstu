#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a[4][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    int f = 0;
    double r = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][0] != a[j][0] and f == 0 and a[i][1] != a[j][1]) {
                int x = a[i][0] - a[j][0];
                int y = a[i][1] - a[j][1];
                r = sqrt(x*x + y*y);
                f = 1;
            }
        }
    }
    cout << r << endl;
    return 0;
}