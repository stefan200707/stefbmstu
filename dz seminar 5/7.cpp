#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<double> vec;
    cout << "Чтобы завершить ввод, введите любую букву \n";
    while (true) {
        double t = 0;
        cin >> t;
        
        if (cin.fail()) {
            break;
        }
        else {
            vec.push_back(t);
        }
    }
    
    cin.clear();
    
    for (double x : vec) cout << x << " ";
    cout << endl;
    vec.erase(remove_if(vec.begin(),vec.end(), [](int x) {return ((x < -50) or (x > 50));}),vec.end());
    for (double x : vec) cout << x << " ";
    cout << endl;
    auto max_it = max_element(vec.begin(),vec.end());
    auto min_it = min_element(vec.begin(),vec.end());
    int sum = accumulate(vec.begin(),vec.end(),0.0);
    double sr = (double) sum/(double) vec.size();
    cout << "Max: " << *max_it << " Min: " << *min_it << " sr: " << sr << "\n";
    int k = 0;
    for_each(vec.begin(),vec.end(), [&k](double t){if (t >= -10.) k++;});
    if (k == vec.size()) {
        cout << "Да, все числа больше либо равны -10 \n";
    }
    else {
        cout << "Нет, не все числа больше либо равны -10 \n";
    }
    return 0;
}