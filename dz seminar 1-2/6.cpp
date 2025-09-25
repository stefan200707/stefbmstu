#include <iostream>
using namespace std;
int main(){
    int f;
    cin >> f;
    if (f < 18) cout << "younger than 18" << endl;
    else if ((f >= 18) and (f <= 60)) cout << "in the middle ages" << endl;
    else if (f > 60) cout << "old" << endl;
    return 0;
}