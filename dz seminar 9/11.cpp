#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> signals;
    for (int i = 0; i < N; i++) {
        double temp;
        cin >> temp;
        signals.push_back(temp);
    }
    unique_ptr<double[]> arr = make_unique<double[]>(N);
    for (int i = 0; i < N; i++) {
        arr[i] = signals[i];
        cout << signals[i] << " ";
    }
    cout << endl;
    double value = 0;
    for_each(signals.begin(), signals.end(), [&value](double n) { value += n; });
    double mean = value / N;
    double minVal = arr[0], maxVal = arr[0];
    for (int i = 0; i < N; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << mean << endl;
    auto normalize = [](unique_ptr<double[]>& data, int size, double maxValue) {
        for (int i = 0; i < size; i++) {
            data[i] = data[i] / maxValue;
        }
    };
    
    auto copyBack = [](const unique_ptr<double[]>& source, vector<double>& target, int size) {
        for (int i = 0; i < size; i++) {
            target[i] = source[i];
        }
    };
    
    normalize(arr, N, maxVal);
    copyBack(arr, signals, N);
    for (int i = 0; i < N; i++) {
        cout << signals[i] << " ";
    }
    cout << endl;
    return 0;
}