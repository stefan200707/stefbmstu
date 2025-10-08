#include <iostream>
using namespace std;
int main() {
    double x, y, z;
    int det[3][4];
    det[0][0] = 1;
    det[0][1] = 1;
    det[0][2] = 1;
    det[0][3] = 6;
    det[1][0] = 2;
    det[1][1] = -1;
    det[1][2] = 3;
    det[1][3] = 14;
    det[2][0] = -1;
    det[2][1] = 4;
    det[2][2] = -1;
    det[2][3] = 2;
    int d = (det[1][1]*det[2][2]-det[1][2]*det[2][1])-(det[1][0]*det[2][2]-det[2][0]*det[1][2])+(det[1][0]*det[2][1]-det[2][0]*det[1][1]);
    int dx = ((6*det[2][2]*det[1][1]+det[0][1]*det[1][2]*2+det[0][2]*14*det[2][1])-(det[0][2]*det[1][1]*2+6*det[1][2]*det[2][1]+det[0][1]*14*det[2][2]));
    x = (double)dx/d;
    int dy = ((det[0][0]*det[2][2]*14+6*det[1][2]*det[2][0]+det[0][2]*det[1][0]*2)-(det[0][2]*14*det[2][0]+det[0][0]*det[1][2]*2+6*det[1][0]*det[2][2]));
    y = (double)dy/d;
    int dz = ((det[0][0]*det[1][1]*2+det[0][1]*14*det[2][0]+6*det[1][0]*det[2][1])-(6*det[1][1]*det[2][0]+det[0][0]*14*det[2][1]+det[0][1]*det[1][0]*2));
    z = (double)dz/d;
    cout << x << " " << y << " " << z << endl;
    return 0;
}