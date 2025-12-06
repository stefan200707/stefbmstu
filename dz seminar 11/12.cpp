#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

int main() {
    vector<int> numbers(100000);
    for (int i = 0; i < 100000; ++i) {
        numbers[i] = i + 1;
    }

    auto measureTime = [](const string& methodName, auto writeFunction) {
        auto start = chrono::steady_clock::now();
        writeFunction();
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << methodName << ": " << duration.count() << " мс" << endl;
    };

    measureTime("Запись всех чисел сразу", [&numbers]() {
        ofstream file("all_at_once.bin", ios::binary);
        file.write(reinterpret_cast<const char*>(numbers.data()), 
                   numbers.size() * sizeof(int));
        file.close();
    });

    return 0;
}