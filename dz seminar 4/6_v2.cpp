#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    int verhl[] = {0,n-1};
    int verhp[] = {n-1,n-1};
    int nizp[] = {0,1};
    int nizl[] = {n-1,0};
    int k = 0;
    int j = 0;
    int i = 0;
    while (k <= n*n) {
        //cout << k << " ";
        k++;
        while (i == verhl[0] and j <= verhl[1] and k <= n*n) {
            a[i][j] = k;
            //cout << a[i][j] << " " << i << " " << j << " " << k << " " <<  endl;
            j++;
            k++;
        }
        j--;
        //cout << i << " " << j << " " << endl;
        i++;
        verhl[0]++;
        verhl[1]--;
        
        if (k > n*n) break;
        while (j == verhp[0] and i <= verhp[1] and k <= n*n) {
            a[i][j] = k;
            //cout << a[i][j] << " " << i << " " << j << " " << k << " " <<  endl;
            i++;
            k++;   
        }
        i--;
        verhp[0]--;
        verhp[1]--;
        j--;
        if (k > n*n) break;
        while (i == nizl[0] and j >= nizl[1] and k <= n*n) {
            a[i][j] = k;
            //cout << a[i][j] << " " << i << " " << j << " " << k << " " <<  endl;
            j--;
            k++;
        }
        i--;
        j++;
        nizl[1]++;
        nizl[0]--;
        if (k > n*n) break;
        while (j == nizp[0] and i >= nizp[1] and k <= n*n) {
            a[i][j] = k;
            //cout << a[i][j] << " " << i << " " << j << " " << k << " " <<  endl;
            i--;
            k++;
        }
        i++;
        nizp[1]++;
        nizp[0]++;
        k--;
        j++;
        //cout << a[i][j] << " " << i << " " << j << " " << k << " " << verhl[0] << " " <<  verhl[1] << endl;
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< n;j++) {
            cout << fixed << setw(n) << a[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}