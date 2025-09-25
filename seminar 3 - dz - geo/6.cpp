#include <iostream>
using namespace std;
int main() {
    int a[4][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    int m[] = {a[1][0]-a[0][0],a[1][1]-a[0][1],a[3][0]-a[2][0],a[3][1]-a[2][1]};
    int d = m[0]*m[2] - m[1]*m[3];
    if (d != 0) {
        cout << "peresecautca" << endl;
    }
    else {
        cout << "neperesecautca" << endl;
    }
    return 0;
}