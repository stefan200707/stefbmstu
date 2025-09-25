#include <iostream>
using namespace std;
int main(){
    int f;
    cin >> f;
    if (f % 15 == 0) cout << "f % 15 == 0" << endl;
    else if (f % 3 == 0) cout << "f % 3 == 0" << endl;
    else if (f % 5 == 0) cout << "f % 5 == 0" << endl;
    else cout << "uvi" << endl;
    return 0;
}