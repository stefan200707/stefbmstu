#include <iostream>
using namespace std;
int main(){
    char c;
    cin >> c;
    int cnt = 0;
    while (c != '.') {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y') {
            cnt += 1;
        }
        cin >> c;
    }
    cout << cnt << endl;
    return 0;
}