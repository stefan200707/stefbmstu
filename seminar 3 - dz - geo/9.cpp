#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int a[n][2];
    int b[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> b[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (a[i][0] > a[j][0]) {
                // Меняем местами точки
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (b[i][0] > b[j][0]) {
                // Меняем местами точки
                swap(b[i][0], b[j][0]);
                swap(b[i][1], b[j][1]);
            }
        }
    }


    for (int i = 0, j = n - 1; i < n; j = i++) {
        int ddt = 0;
        bool validAB = true;
        int pointsOnAB = 0;
        int A[] = {a[i][0],a[i][1]};
        int B[] = {a[j][0],a[j][1]};
        int C[] = {b[i][0],b[i][1]};
        int D[] = {b[j][0],b[j][1]};
        int AB[] = {A[0],A[1],B[0],B[1]};
        int CD[] = {C[0],C[1],D[0],D[1]};
        for (int i = 2; i < 4; i++) {
            int x = a[i][0], y = a[i][1];
            if ((y - A[1]) * (B[0] - A[0]) == (x - A[0]) * (B[1] - A[1])) {
                pointsOnAB++;
            }
        }
        if (pointsOnAB == 2) {
            validAB = false;
        }
        bool validCD = true;
        int pointsOnCD = 0;
        for (int i = 0; i < 2; i++) {
            int x = a[i][0], y = a[i][1];
            if ((y - C[1]) * (D[0] - C[0]) == (x - C[0]) * (D[1] - C[1])) {
                pointsOnCD++;
            }
        }
        if (pointsOnCD == 2) {
            validCD = false;
        }        
        int d1 = ((B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]));
        int d2 = ((B[0] - A[0]) * (D[1] - A[1]) - (B[1] - A[1]) * (D[0] - A[0]));
        
        if (!validAB || !validCD) {
            ddt++;
        } else if (d1 * d2 <= 0) {
            cout << "peresec" << endl;
            return 0;
        } 
    }
    cout << "neperesec" << endl;
    return 0;
}