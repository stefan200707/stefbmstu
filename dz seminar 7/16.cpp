#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    minVal = *p;
    maxVal = *p;
    avgVal = 0.0; 
    const double* end = data.data() + data.size();
    
    for (; p != end; p++) {
        if (*p < minVal) minVal = *p;
        if (*p > maxVal) maxVal = *p;
        avgVal += *p;
    }
    avgVal /= data.size();
}
int main() {
    vector<double> data;
    int n;
    cin >> n;
    for (int i = 0;i < n; i++) {
        double t;
        cin >> t;
        data.push_back(t);
    }
    double minVal, maxVal, avgVal;
    analyzePressure(data,minVal,maxVal,avgVal);
    cout << minVal << " " << maxVal << " " << avgVal << endl;
}