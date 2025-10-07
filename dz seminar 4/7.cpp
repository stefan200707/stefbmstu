#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    int a[n][n];
    int verhl[] = {0,n-1};
    int verhp[] = {n-1,n-1};
    int nizp[] = {0,1};
    int nizl[] = {n-1,0};
    int k = 0;
    int j = 0;
    int i = 0;
    cout << "**********" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << "***********" << endl;
    int t = 0;
    int d = 0;
    while (k <= n*n) {
        //cout << k << " ";
        k++;
        while (i == verhl[0] and j <= verhl[1] and k <= n*n) {
            a[t][d] = b[i][j];
            //cout << a[t][d] << " " << t << " " << d << " " << b[i][j] << " " <<  endl;
            j++;
            k++;
            d++;
            t = t + (d % n == 0);
            d %= n;
        }
        j--;

        i++;
        verhl[0]++;
        verhl[1]--;
        if (k > n*n) break;
        while (j == verhp[0] and i <= verhp[1] and k <= n*n) {
            a[t][d] = b[i][j];
            //cout << a[t][d] << " " << t << " " << d << " " << b[i][j] << " " <<  endl;
            i++;
            k++;
            d++;
            t = t + (d % n == 0);
            d %= n;
        }
        i--;
        verhp[0]--;
        verhp[1]--;
        j--;
        if (k > n*n) break;
        while (i == nizl[0] and j >= nizl[1] and k <= n*n) {
            a[t][d] = b[i][j];
            //cout << a[t][d] << " " << t << " " << d << " " << b[i][j] << " " <<  endl;
            j--;
            k++;
            d++;
            t = t + (d % n == 0);
            d %= n;
        }
        i--;
        j++;
        nizl[1]++;
        nizl[0]--;
        if (k > n*n) break;
        while (j == nizp[0] and i >= nizp[1] and k <= n*n) {
            a[t][d] = b[i][j];
            //cout << a[i][j] << " " << t << " " << d << " " << b[i][j] << " " <<  endl;
            i--;
            k++;
            d++;
            t = t + (d % n == 0);
            d %= n;
        }
        //cout << a[t][d] << " " << t << " " << d << " " << b[i][j] << "**0**" << endl;
        i++;
        nizp[1]++;
        nizp[0]++;
        k--;
        j++;
        //cout << a[t][d] << " " << t << " " << d << " " << b[i][j] << " ***** " << endl;
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
    
    
    return 0;
}