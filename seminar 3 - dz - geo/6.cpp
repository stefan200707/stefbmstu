#include <iostream>
using namespace std;
int main() {
    int a[4][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (a[i][0] > a[j][0]) {
                // Меняем местами точки
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }

    for (int i = 2; i < 4; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (a[i][0] > a[j][0]) {
                // Меняем местами точки
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }

    int A[] = {a[0][0],a[0][1]};
    int B[] = {a[1][0],a[1][1]};
    int C[] = {a[2][0],a[2][1]};
    int D[] = {a[3][0],a[3][1]};
    int AB[] = {A[0],A[1],B[0],B[1]};
    int CD[] = {C[0],C[1],D[0],D[1]};
    int d1 = ((B[0] - A[0])*(C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]));
    int d2 = ((B[0] - A[0])*(D[1] - A[1]) - (B[1] - A[1]) * (D[0] - A[0]));
    if (d1 * d2 <= 0) {
        cout << "peresec" << endl;
    }
    else {
        cout << "neperesec" << endl;
    }
    return 0;
}