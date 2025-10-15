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
    vec.erase(remove_if(vec.begin(),vec.end(),[](double x) {return x < 0.1;}),vec.end());
    int sum = accumulate(vec.begin(),vec.end(),0);
    double avg = (double) sum / (double) vec.size();
    int max_it = *max_element(vec.begin(), vec.end());
    int k;
    for_each(vec.begin(),vec.end(), [&k](double t){if (t >= 0.5) k++;});
    int ind;
    for (int i = 0; i < n; i++) {
        if (vec[i] == max_it) {
            ind = i;
        }
    }
    for (int i = ind-9; i <= ind; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    if (k == vec.size()) {
        cout << "Все значения превышают порог" << endl;
    }
    else {
        cout << "Не все значения превышают порог" << endl;
    }
    cout << avg << " " << max_it << endl;
    return 0;
}
