#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector <int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Вектор чисел: ";
    for_each(numbers.begin(), numbers.end(), [](int num) {
        cout << num << " ";
    });
    cout << endl;
    return 0;
}