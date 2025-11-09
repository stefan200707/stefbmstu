#include <iostream>
using namespace std;
int **transpose(int **matrix, int n, int m) {
    int **result = new int*[m];
    for (int i = 0; i < m; i++) {
        result[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int** transposed = transpose(matrix, n, m);
    printMatrix(transposed, m, n);
    return 0;
}