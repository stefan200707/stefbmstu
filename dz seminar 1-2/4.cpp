#include <iostream>
using namespace std;
int main(){
    int f;
    cin >> f;
    string res = (f % 2 != 0) ? "nch" : "ch";
    cout << res << endl;
    return 0;
}