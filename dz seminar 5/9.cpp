#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> vec;
    for (int x = 0; x < 20; x++) {
        int t;
        cin >> t;
        vec.push_back(t);
    }

    int max_it = *max_element(vec.begin(), vec.end());
    int min_it = *min_element(vec.begin(), vec.end());
    int sum = accumulate(vec.begin(), vec.end(), 0);
    double sr = static_cast<double>(sum) / vec.size();

    sort(vec.begin(), vec.end());
    double median = (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;

    cout << "Максимум: " << max_it << "\n";
    cout << "Минимум: " << min_it << "\n";
    cout << "Среднее: " << sr << "\n";
    cout << "Медиана: " << median << "\n";

    int k = count_if(vec.begin(), vec.end(), [](int t) {
        return t >= 10 && t <= 90;
    });

    if (k == vec.size()) {
        cout << "Двигатель работал всё время";
    } else {
        cout << "Двигатель не работал всё время";
    }

    cout << endl << "Количество значений в диапазоне [10,90]: " << k << " " << vec.size() << endl;
    return 0;
}
