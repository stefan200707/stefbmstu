#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int A[2], B[2], C[2];
    for (int i = 0; i < 2; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> C[i];
    }
    int M[3][3];
    M[0][0] = A[0];
    M[0][1] = A[1];
    M[0][2] = 1;
    M[1][0] = B[0];
    M[1][1] = B[1];
    M[1][2] = 1;
    M[2][0] = C[0];
    M[2][1] = C[1];
    M[2][2] = 1;
    int d = (1*(M[1][0]*M[2][1]-M[2][0]*M[1][1]) - 1*(M[0][0]*M[2][1] - M[2][1]*M[0][1]) + 1*(M[0][0]*M[1][1] - M[1][0]*M[0][1]));
    cout <<  (double) abs(d)/2. << endl;
    return 0;
}