#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int c = 0;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int min_str[n];
    int max_str[n];
    int min_stolb[m];
    int max_stolb[m];
    for (int i = 0; i < n; i++) {
        int min_st = a[i][0];
        for (int j = 0; j < m; j++) {
            if (min_st < a[i][j]);
        }
    }
    
    return 0;
}