#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double mas[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> mas[i][j];
        }
    }
    double px, py;
    cin >> px >> py;
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        double xi = mas[i][0], yi = mas[i][1];
        double xj = mas[j][0], yj = mas[j][1];

        if (xi == px and yi == py) { // проверка на вершину
            inside = true;
            break;
        }

        if (yi == py && yj == py) { // проверка на горизонтальную прямую
            if ((xi <= px && px <= xj) || (xj <= px && px <= xi)) {
                inside = true;
                break;
            }
        }
        if ((yi > py) != (yj > py)) { // Точка между y-координатами ребра
            // Вычисляем x координату пересечения
            double x_intersect = xj + (px - xj) * (yj - yi) / (xj - xi);
            
            if (px < x_intersect) {
                inside = !inside; // Меняем флаг
            } else if (px == x_intersect) {
                inside = true; // Точка лежит на ребре
                break;
            }
        }
    }
    if (inside) {
        cout << "ВНУТРИ многоугольника" << endl;
    } 
    else {
        cout << "СНАРУЖИ многоугольника" << endl;
    }
    return 0;
}