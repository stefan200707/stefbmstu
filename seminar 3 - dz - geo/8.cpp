#include <iostream>
using namespace std;
int main() {
    int mas[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0;j < 2; j++) {
            cin >> mas[i][j];
        }
    }
    int dx = mas[1][0] - mas[0][0];
    int dy = mas[1][1] - mas[0][1];
    double res = sqrt(dx*dx +dy*dy);
    cout << res << endl;
    return 0;
}