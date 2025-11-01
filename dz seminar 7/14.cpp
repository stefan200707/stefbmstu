#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
double computerRMS(const vector<double> &signal) {
    const double* p = signal.data(); 
    double sum = 0.0;
    double n = signal.size(); 

    for (int i = 0; i < n; ++i) {
        sum += pow(*(p+i),2); 
    }
    return sqrt(sum/n); 
}
int main() {
    vector<double> signal;
    for (int i = 0; i < 5; i++) {
        double t;
        cin >> t;
        signal.push_back(t);
    }
    cout << computerRMS(signal) << endl;
    return 0;
}