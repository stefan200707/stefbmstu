#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector <int> numbers;
    numbers.reserve(10);
    int t;
    for (int i = 0; i < 10; i++) {
        cin >> t;
        numbers.push_back(t);
    }
    cout << "Вектор чисел: ";
    for_each(numbers.begin(), numbers.end(), [](int num) {
        cout << num*2 << " ";
    });
    cout << endl;
    return 0;
}