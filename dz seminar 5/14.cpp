#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>   
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    vector<double> vec(24);
    for (int i = 0; i < 24; i++) {
        vec[i] = 100 + rand() % 401; 
    }
    double sum;
    for (int x : vec) cout << x << " ";
    cout << endl;
    sum = accumulate(vec.begin(),vec.end(),0);
    double sr = (double) sum / (double) vec.size();
    double max_it = *max_element(vec.begin(),vec.end());
    cout << sum << " " << sr << " " << max_it << endl;
    vector<double> otkl(vec.size());
    transform(vec.begin(),vec.end(),otkl.begin(), [sr](double ot){return sr-ot;});
    sort(vec.begin(),vec.end());
    cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << " " << vec[4] << endl;
    return 0;
}