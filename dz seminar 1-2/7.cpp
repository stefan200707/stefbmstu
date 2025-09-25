#include <iostream>
using namespace std;
int main(){
    int f;
    cin >> f;
    for (int i = 1; i*i <= f; i++) {
        cout << i*i << " ";
    }
    cout << endl;
    return 0;
}