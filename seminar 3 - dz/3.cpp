#include <iostream>
using namespace std;
int main() {
    double a[15];
    for (int i = 0; i < 15; i++) cin >> a[i];
    double min = a[0]+1, max = a[14];
    int mini = -1, maxi = -1;
    for (int i = 0; i < 15; i++) {
        if (a[i] > max) { 
            max = a[i];
            maxi = i;
        }
        if (a[i] < min) {
            min = a[i];
            mini = i;
        }
    }
    cout << max << " " << maxi << " " << min << " " << mini << endl;
    int temp = a[14];
    a[14] = max;
    a[maxi] = temp;
    int temp2 = a[0];
    a[0] = min;
    a[mini] = temp2;
    for (int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}