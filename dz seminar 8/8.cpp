#include <iostream>
#include <iomanip>
using namespace std;

void update(double** matrix, int n, int m, int k) {
    for (int iter = 0; iter < k; iter++) {
        double** temp = new double*[n];
        for (int i = 0; i < n; i++) {
            temp[i] = new double[m];
            for (int j = 0; j < m; j++) {
                temp[i][j] = matrix[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n/2 && j == m/2) continue;
                
                double sum = 0;
                int count = 0;
                
                if (i > 0) { sum += temp[i-1][j]; count++; }
                if (i < n-1) { sum += temp[i+1][j]; count++; }
                if (j > 0) { sum += temp[i][j-1]; count++; }
                if (j < m-1) { sum += temp[i][j+1]; count++; }
                
                if (count > 0) matrix[i][j] = sum / count;
            }
        }
        
        for (int i = 0; i < n; i++) delete[] temp[i];
        delete[] temp;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 20.0;
        }
    }
    
    matrix[n/2][m/2] = 100.0;
    
    update(matrix, n, m, k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}