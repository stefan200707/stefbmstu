#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int k = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) if (a[i] > pow(2, i)) k++;
    cout << k << endl;
}