#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> vec;
    for (int x = 0; x < 30; x++) {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    int sum = accumulate(vec.begin(),vec.end(),0);
    double avg = (double) sum / (double) vec.size();
    auto [min_it, max_it] = minmax_element(vec.begin(), vec.end());
    cout << "пиковые дни" << endl;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > avg * 1.2) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    cout << sum << " " << avg << " " << *min_it << " " << *max_it << endl;
    return 0;
}
