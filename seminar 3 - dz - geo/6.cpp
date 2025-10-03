#include <iostream>
using namespace std;

int main() {
    int a[4][2];
    
    // Ввод точек
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    
    // Сортировка первых двух точек по x
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 2; j++) {
            if (a[i][0] > a[j][0]) {
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }
    
    // Сортировка вторых двух точек по x
    for (int i = 2; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) { // Исправлено: j < 4 вместо j < 2
            if (a[i][0] > a[j][0]) {
                swap(a[i][0], a[j][0]);
                swap(a[i][1], a[j][1]);
            }
        }
    }
    
    int A[] = {a[0][0], a[0][1]};
    int B[] = {a[1][0], a[1][1]};
    int C[] = {a[2][0], a[2][1]};
    int D[] = {a[3][0], a[3][1]};
    
    // Проверка, что прямая AB не проходит через 3 точки
    bool validAB = true;
    int pointsOnAB = 0;
    
    // Проверяем точки C и D на принадлежность прямой AB
    for (int i = 2; i < 4; i++) {
        int x = a[i][0], y = a[i][1];
        // Уравнение прямой через A и B: (y - A[1])*(B[0] - A[0]) = (x - A[0])*(B[1] - A[1])
        if ((y - A[1]) * (B[0] - A[0]) == (x - A[0]) * (B[1] - A[1])) {
            pointsOnAB++;
        }
    }
    
    // Если обе точки C и D лежат на прямой AB, то это недопустимо
    if (pointsOnAB == 2) {
        validAB = false;
    }
    
    // Проверка, что прямая CD не проходит через 3 точки
    bool validCD = true;
    int pointsOnCD = 0;
    
    // Проверяем точки A и B на принадлежность прямой CD
    for (int i = 0; i < 2; i++) {
        int x = a[i][0], y = a[i][1];
        // Уравнение прямой через C и D: (y - C[1])*(D[0] - C[0]) = (x - C[0])*(D[1] - C[1])
        if ((y - C[1]) * (D[0] - C[0]) == (x - C[0]) * (D[1] - C[1])) {
            pointsOnCD++;
        }
    }
    
    // Если обе точки A и B лежат на прямой CD, то это недопустимо
    if (pointsOnCD == 2) {
        validCD = false;
    }
    
    // Проверка пересечения отрезков
    int d1 = ((B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]));
    int d2 = ((B[0] - A[0]) * (D[1] - A[1]) - (B[1] - A[1]) * (D[0] - A[0]));
    
    if (!validAB || !validCD) {
        cout << "neperesec" << endl;
    } else if (d1 * d2 <= 0) {
        cout << "peresec" << endl;
    } else {
        cout << "neperesec" << endl;
    }
    
    return 0;
}