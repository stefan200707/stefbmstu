#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c = 0;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < n; j++) {
            c += a[i][j];
        }
    }
    int cnt = 0;
    int s3 = 0;
    //cout << c << endl;
    int s4 = 0;
    for (int i = 0; i < n; i++) {
        int s1 = 0;
        int s2 = 0;

        for (int j = 0, t = n - 1 - i; j < n; j++,t--) {
            s1 += a[i][j];
            s2 += a[j][i];
            if (i == j) s3 += a[i][j];
            if (i == n - t - 1) s4 += a[i][t];
        }
        if (s1 == c and s2 == c) {
            cnt++;
        }
        if (s3 == c and s4 == c) cnt++;
        //cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << cnt << " " << endl;
    }
    if (cnt == n + 1) cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}