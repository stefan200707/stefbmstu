#include <iostream>
using namespace std;
int main() {
    double x, y;
    int det[2][3];
    det[0][0] = 2;
    det[0][1] = 3;
    det[0][2] = 13;
    det[1][0] = 5;
    det[1][1] = -1;
    det[1][2] = 9;
    int d = (det[0][0]*det[1][1] - det[1][0]*det[0][1]);
    int dx = (det[0][2]*det[1][1] - det[0][1]*det[1][2]);
    x = (double)dx/d;
    int dy = (det[0][0]*det[1][2]-det[0][2]*det[1][0]);
    y = (double)dy/d;
    cout << x << " " << y << endl;
    return 0;
}