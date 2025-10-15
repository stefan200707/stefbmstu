#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n = 50;
    vector<int> vec;
    vec.reserve(50);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        vec.push_back(rand() % 180+1);
    }
    for (int x : vec) cout << x << " ";
    cout << endl;
    vec.erase(remove_if(vec.begin(),vec.end(), [](int n){ return n > 120; }), vec.end());
    int sum = accumulate(vec.begin(),vec.end(),0.0);
    double sr = (double) sum/(double) vec.size();
    sort(vec.begin(),vec.end());
    for (int x : vec) cout << x << " ";
    cout << endl;
    if (vec[0] == 0) {
        cout << "значения были больше нуля не во всех случаях";
    }
    else {  
        cout << "Все значения были болььше 0";
    }
    cout << endl;
    int ind;
    auto max_it = max_element(vec.begin(),vec.end());
    for (int i = 0; i < n; i++) {
        if (vec[i] == *max_it) {
            ind = i;
        }
    }
    for (int i = ind-9; i <= ind; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}