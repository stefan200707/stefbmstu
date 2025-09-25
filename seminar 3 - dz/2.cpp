#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int ch = 0, nch;
    for (int i = 0; i < n; i++) cin >> a[i];
    nch = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 and a[i] > nch) {
            nch = a[i];
        }
        if (a[i] % 2 == 0) ch++;
    } 
    cout << "max nch = " << nch << " ch = " << ch << endl;
    return 0;
}