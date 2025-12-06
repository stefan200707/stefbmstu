#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    ofstream testFile("sensor_data.txt");
    if (testFile.is_open()) {
        testFile << "25.3\n-12.7\n38.9\n22.1\n999.9\n-60.5\n45.0\n-10.2\n150.0\n";
        testFile.close();
        cout << "Тестовый файл создан\n";
    }

    ifstream input("sensor_data.txt");
    if (!input) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    vector<double> temps;
    double temp;

    while (input >> temp) {
        temps.push_back(temp);
    }
    input.close();

    auto isInvalid = [](double t) { return t < -50.0 || t > 50.0; };
    temps.erase(remove_if(temps.begin(), temps.end(), isInvalid), temps.end());

    cout << "Корректных значений: " << temps.size() << endl;

    if (!temps.empty()) {
        double sum = accumulate(temps.begin(), temps.end(), 0.0);
        cout << fixed << setprecision(2);
        cout << "Средняя температура: " << sum / temps.size() << "°C" << endl;
    }

    ofstream output("filtered_data.txt");
    output << fixed << setprecision(1);
    for (const auto& t : temps) {
        output << t << endl;
    }
    output.close();

    return 0;
}