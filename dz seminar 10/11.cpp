#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ifstream file("vibration_log.txt");
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл vibration_log.txt" << endl;
        return 1;
    }

    double value;
    vector<double> data;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();

    if (data.empty()) {
        cerr << "Ошибка: В файле нет данных" << endl;
        return 1;
    }

    auto count_above = count_if(data.begin(), data.end(),
                              [](double x) { return x > 0.05; });
    double ratio = static_cast<double>(count_above) / data.size();

    auto min_val = *min_element(data.begin(), data.end());
    auto max_val = *max_element(data.begin(), data.end());

    cout << ratio << " " << min_val << " " << max_val << endl;

    return 0;
}