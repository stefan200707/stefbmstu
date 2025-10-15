#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n = 50;
    vector<double> vec;
    for (int x = 0; x < 50; x++) {
        double t;
        cin >> t;
        vec.push_back(t);
    }
    int min_it = *min_element(vec.begin(),vec.end());
    int max_it = *max_element(vec.begin(),vec.end());
    int k;
    for_each(vec.begin(),vec.end(), [&k,max_it](double t){if (t >= 0.05 * max_it) k++;});
    if (k == vec.size()) {
        cout << "не падал" << endl;
    }
    else {
        cout << "падал" << endl;
    }
    double sr = vec[0] - vec[vec.size()-1];
    sort(vec.begin(),vec.end());
    double median = (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;
    cout << min_it << " " << sr << " " << median << endl;
    return 0;
}
