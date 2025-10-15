#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
    vector<int> vec;
    vec.reserve(20);
    for (int x = 0; x < 20; x++) { //ввод в вектор
        int t;
        cin >> t;
        vec.push_back(t);
    }
    auto max_it = max_element(vec.begin(),vec.end());
    auto min_it = min_element(vec.begin(),vec.end());
    int sum = accumulate(vec.begin(),vec.end(),0);
    double sr = (double) sum/20.;
    sort(vec.begin(),vec.end());
    int median = (vec[vec.size()/2 - 1] + vec[vec.size()/2]) / 2.0;
    cout << *max_it << "\n" << *min_it << "\n" << sr << "\n" << median << "\n";
    return 0;
}