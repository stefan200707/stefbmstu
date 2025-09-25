#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    } // создали массив и инициализировали его

    int point[1][2];
    for (int i = 0; i < 2; i++) {
        cin >> point[0][i];
    } // создали точку

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][0] > a[j][0]) {
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int ab[] = {a[i][0] - a[i+1][0], a[i][1]-a[i+1][1]};
        double pvector[] = {(point[0][0]-ab[0])/2., (point[0][1] - ab[1])/2.};
        double d = ab[0]*pvector[0] - ab[1]*pvector[1];
        if (d != 0) {
            cnt++;
        }
        cout << ab[0] << " " << ab[1] << " " << pvector[0] << " " << pvector[1] << endl; 
    }
    int ab[] = {a[0][0] - a[n-1][0], a[0][1]-a[n-1][1]};
    double pvector[] = {(point[0][0]-ab[0])/2., (point[0][1] - ab[1])/2.};
    double d = ab[0]*pvector[0] - ab[1]*pvector[1];
    if (d != 0) {
        cnt++;
    }
    if (cnt % 2 == 0) {
        cout << "vne" << endl;
    }
    if (cnt % 2 != 0) {
        cout << "vnutri" << endl;
    }
    return 0;
}