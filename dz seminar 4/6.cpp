#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    a[0][0] = 1;
    int k = 1;
    int i = 0, j = 0;
    int var = 2;
    while (k < n*n) {
        if (i == k / (n*(1+n%2)) and j < n - k / (n*(1+n%2))) {
            j++;    
            a[i][j] = var;
            //cout << var << " ";
        }
        else if (j == n - k/(n*n-n) - 1 and i < n - 1 - k/(n*2)) {
            i++;
            a[i][j] = var;
            //cout << var << " ";

        }
        else if ((i == n - 1) and j > 0) {
            j--;
            a[i][j] = var;
            //cout << "var " << var << " " << "i " << i << " " << "j " << j << " ";
        }
        else if (j == 0) {
            if (i > 0 + k/(n*2)) {
                i--;
                a[i][j] = var;
                //cout << "var " << var << " " << "i " << i << " " << "j " << j << " ";
            }
        }
        //else if ()
        k++;
        var++;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}