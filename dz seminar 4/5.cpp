#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int minRow[n], maxRow[n];
    for (int i = 0; i < n; i++) {
        minRow[i] = a[i][0];
        maxRow[i] = a[i][0];
        for (int j = 1; j < m; j++) {
            if (a[i][j] < minRow[i]) minRow[i] = a[i][j];
            if (a[i][j] > maxRow[i]) maxRow[i] = a[i][j];
        }
    }

    int minCol[m], maxCol[m];
    for (int j = 0; j < m; j++) {
        minCol[j] = a[0][j];
        maxCol[j] = a[0][j];
        for (int i = 1; i < n; i++) {
            if (a[i][j] < minCol[j]) minCol[j] = a[i][j];
            if (a[i][j] > maxCol[j]) maxCol[j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == minRow[i] && a[i][j] == maxCol[j]) {
                cout << "type=A (" << i << "," << j << ") = " << a[i][j] << endl;
            }
            if (a[i][j] == maxRow[i] && a[i][j] == minCol[j]) {
                cout << "type=B (" << i << "," << j << ") = " << a[i][j] << endl;
            }
        }
    }

    return 0;
}
