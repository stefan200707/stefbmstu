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
    auto it = find(vec.begin(),vec.end(), 7);
    if (*it != 0) {
        cout << "число найдено \n";
    }
    else {
        cout << "Число не найдено";
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for (int x : vec) cout << x << " ";
    cout << "\n";
    return 0;
}