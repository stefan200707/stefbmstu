#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Ввод координат четырех точек
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    
    cout << "Введите координаты точки A (x1 y1 z1): ";
    cin >> x1 >> y1 >> z1;
    
    cout << "Введите координаты точки B (x2 y2 z2): ";
    cin >> x2 >> y2 >> z2;
    
    cout << "Введите координаты точки C (x3 y3 z3): ";
    cin >> x3 >> y3 >> z3;
    
    cout << "Введите координаты точки D (x4 y4 z4): ";
    cin >> x4 >> y4 >> z4;
    
    // Вычисление квадратов расстояний от начала координат
    double r1_sq = x1*x1 + y1*y1 + z1*z1;
    double r2_sq = x2*x2 + y2*y2 + z2*z2;
    double r3_sq = x3*x3 + y3*y3 + z3*z3;
    double r4_sq = x4*x4 + y4*y4 + z4*z4;
    
    // Матрица коэффициентов для системы уравнений
    double matrix[4][5];
    
    // Заполнение матрицы системы уравнений
    matrix[0][0] = x1; matrix[0][1] = y1; matrix[0][2] = z1; matrix[0][3] = 1; matrix[0][4] = -r1_sq;
    matrix[1][0] = x2; matrix[1][1] = y2; matrix[1][2] = z2; matrix[1][3] = 1; matrix[1][4] = -r2_sq;
    matrix[2][0] = x3; matrix[2][1] = y3; matrix[2][2] = z3; matrix[2][3] = 1; matrix[2][4] = -r3_sq;
    matrix[3][0] = x4; matrix[3][1] = y4; matrix[3][2] = z4; matrix[3][3] = 1; matrix[3][4] = -r4_sq;
    
    // Метод Гаусса для решения системы 4x4
    int n = 4;
    
    // Прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {
        // Поиск главного элемента
        double max_element = fabs(matrix[i][i]);
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > max_element) {
                max_element = fabs(matrix[k][i]);
                max_row = k;
            }
        }
        
        // Перестановка строк
        for (int k = i; k < n + 1; k++) {
            double temp = matrix[i][k];
            matrix[i][k] = matrix[max_row][k];
            matrix[max_row][k] = temp;
        }
        
        // Обнуление элементов под главной диагональю
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    
    // Обратный ход метода Гаусса
    double solution[4];
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    
    // Коэффициенты A, B, C, D
    double A = solution[0];
    double B = solution[1];
    double C = solution[2];
    double D = solution[3];
    
    // Координаты центра сферы
    double x0 = -A / 2;
    double y0 = -B / 2;
    double z0 = -C / 2;
    
    // Радиус сферы
    double r = sqrt(x0*x0 + y0*y0 + z0*z0 - D);
    
    // Вывод результатов
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "Коэффициенты уравнения сферы:" << endl;
    cout << "A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;
    cout << "\nУравнение сферы в развернутом виде:" << endl;
    cout << "x² + y² + z² + (" << A << ")x + (" << B << ")y + (" << C << ")z + (" << D << ") = 0" << endl;
    cout << "\nКоординаты центра сферы:" << endl;
    cout << "x₀ = " << x0 << ", y₀ = " << y0 << ", z₀ = " << z0 << endl;
    cout << "\nРадиус сферы:" << endl;
    cout << "r = " << r << endl;
    cout << "\nУравнение сферы в стандартном виде:" << endl;
    cout << "(x " << (x0 >= 0 ? "- " : "+ ") << fabs(x0) << ")² + ";
    cout << "(y " << (y0 >= 0 ? "- " : "+ ") << fabs(y0) << ")² + ";
    cout << "(z " << (z0 >= 0 ? "- " : "+ ") << fabs(z0) << ")² = " << (r*r) << endl;
    
    return 0;
}