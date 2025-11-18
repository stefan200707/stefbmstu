#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <numeric>
#include <string>  
using namespace std;

int main() {
    map<string, vector<double>> sensorData;  
    ifstream read("temperature_data.txt");       
    string line;
    
    while (getline(read, line)) {
        stringstream ss(line);
        string sensorName;
        double temperature;
        
        if (ss >> sensorName) {
            while (ss >> temperature) {
                sensorData[sensorName].push_back(temperature);
            }
        }
    }
    
    for (const auto& sensor : sensorData) {
        cout << "Датчик: " << sensor.first << " - Температуры: ";
        auto min_temp = *min_element(sensor.second.begin(), sensor.second.end());
        auto max_temp = *max_element(sensor.second.begin(), sensor.second.end());
        double sum = accumulate(sensor.second.begin(),sensor.second.end(),0.0);
        int cnt = 0;
        for (const auto& temp : sensor.second) {
            cnt++;
        }
        cout << sum/cnt << " " << min_temp << " " << max_temp << endl;
        
    }
    
    return 0;
}