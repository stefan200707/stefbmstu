#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][0] > a[j][0]) {
                // Меняем местами точки
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }
    
    double perimetr = 0;
    for (int i = 0; i < n - 1; i++) {
        int bx = a[i][0] - a[i+1][0];
        int by = a[i][1] - a[i+1][1];
        double vect = sqrt(bx*bx + by*by);
        perimetr += vect;
    }
    int bx = a[n-1][0] - a[0][0];
    int by = a[n-1][1] - a[0][1];
    double vect = sqrt(bx*bx + by*by);
    perimetr += vect;
    cout << perimetr << endl;
    return 0;
}