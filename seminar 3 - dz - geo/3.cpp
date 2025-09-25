#include <iostream>
using namespace std;
int main() {
    int a[3][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    double cx = (a[0][0] + a[1][0] + a[2][0]) / 3.;
    double cy = (a[0][1] + a[1][1] + a[2][1]) / 3.;
    cout << cx << " " << cy << endl;
    return 0;
}