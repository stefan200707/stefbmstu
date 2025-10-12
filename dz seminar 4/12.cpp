#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A[2]; 
    cin >> A[0] >> A[1];
    
    double sigma;
    cin >> sigma;
    
    sigma = sigma * M_PI / 180.0;
    
    double C[2][2];
    C[0][0] = cos(sigma);
    C[0][1] = -sin(sigma);
    C[1][0] = sin(sigma);
    C[1][1] = cos(sigma);
    
    double RES[2];
    RES[0] = C[0][0] * A[0] + C[0][1] * A[1];
    RES[1] = C[1][0] * A[0] + C[1][1] * A[1];

    cout.precision(2);
    cout << fixed;
    for (int i = 0; i < 2; i++) {
        cout << RES[i] << endl;
    }
    
    return 0;
}