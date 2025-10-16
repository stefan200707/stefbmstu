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
    vec.erase(remove_if(vec.begin(),vec.end(),[](double t){return (t < 0 or t > 12);}),vec.end());
    int sum = accumulate(vec.begin(),vec.end(),0);
    double sr = (double) sum/ (double) vec.size();
    auto [min_it, max_it] = minmax_element(vec.begin(), vec.end());
    for_each(vec.begin(),vec.end(), [](double t){if (t > 8) cout << t << " ";});
    cout << endl;
    cout << sr << " " << *min_it << " " << *max_it << endl;
    return 0;
}
