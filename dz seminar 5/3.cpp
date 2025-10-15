#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector <int> numbers;
    numbers.reserve(20);
    int t;
    for (int i = 0; i < 20; i++) {
        cin >> t;
        numbers.push_back(t);
    }
    auto p = max_element(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });
    cout << *p << endl;
    return 0;
}