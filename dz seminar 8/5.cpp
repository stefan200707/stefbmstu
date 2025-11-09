#include <iostream>
using namespace std;

void arrays(int **arr, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int sum1 = 0, sum2 = 0;
            
            for (int z = 0; z < m; z++) {
                sum1 += arr[j][z];
                sum2 += arr[j + 1][z];
            }
            
            if (sum1 > sum2) {
                for (int z = 0; z < m; z++) {
                    int temp = arr[j][z];
                    arr[j][z] = arr[j + 1][z];
                    arr[j + 1][z] = temp;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    arrays(arr, n, m);
    
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}