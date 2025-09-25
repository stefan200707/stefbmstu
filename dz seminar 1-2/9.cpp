#include <iostream>
using namespace std;
int main(){
    int l,su = 0;
    cin >> l;
    for (int i = 0; i < l; i++) {
        if (i % 2 == 0 or i % 5 == 0) {
            su += i;
        }
    }
    cout << su << endl;
    return 0;
}