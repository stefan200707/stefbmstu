#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>   
#include <ctime>
using namespace std;

int main() {
    vector<vector<double>> temp(5, vector<double>(30));
    vector<vector<double>> pressure(5, vector<double>(100));
    vector<vector<double>> rtemp(5, vector<double>(30, 0)); 
    vector<vector<double>> rpressure(5, vector<double>(100, 0)); 

    // Ввод данных
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 30; y++) {
            cin >> temp[x][y];
        }
    }
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 100; y++) {
            cin >> pressure[x][y];
        }
    }

    double sum[5];
    for (int x = 0; x < 5; x++) {
        sum[x] = accumulate(temp[x].begin(), temp[x].end(), 0.0);
        sum[x] = sum[x] / temp[x].size();
    }
    cout << sum[0] << " " << sum[1] << " " << sum[2] << " " << sum[3] << " " << sum[4] << endl;


    double minmax[5][2]; 
    for (int x = 0; x < 5; x++) {
        auto result = minmax_element(pressure[x].begin(), pressure[x].end());
        minmax[x][0] = *result.first;   
        minmax[x][1] = *result.second;
    }
    cout << minmax[0][0] << " " << minmax[0][1] << "\n" 
         << minmax[1][0] << " " << minmax[1][1] << "\n" 
         << minmax[2][0] << " " << minmax[2][1] << "\n" 
         << minmax[3][0] << " " << minmax[3][1] << "\n" 
         << minmax[4][0] << " " << minmax[4][1] << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 29; j++) {
            rtemp[i][j] = temp[i][j+1] - temp[i][j];
        }
        for (int j = 0; j < 99; j++) { 
            rpressure[i][j] = pressure[i][j+1] - pressure[i][j];
        }
    }

    cout << "rtemp \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 30; j++) {
            cout << rtemp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "rpress \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 100; j++) {
            cout << rpressure[i][j] << " ";
        }
        cout << endl;
    }

    double tminmax[5][2];
    int maxr = -1;
    int ch = -1;
    for (int x = 0; x < 5; x++) {
        auto result = minmax_element(temp[x].begin(), temp[x].end());
        tminmax[x][0] = *result.first;   
        tminmax[x][1] = *result.second;
        int range = tminmax[x][1] - tminmax[x][0];
        if (range > maxr) {
            maxr = range;
            ch = x;
        }
    }
    cout << "kanal: " << ch << endl;

    vector<vector<double>> normPress = pressure;
    for (int i = 0; i < 5; i++) {
        double minP = minmax[i][0], maxP = minmax[i][1];
        transform(pressure[i].begin(), pressure[i].end(), normPress[i].begin(),
                  [minP, maxP](double v){ return (v - minP) / (maxP - minP); });
    }

    cout << "Пики давления (>0.9) по каналам:\n";
    for (int i = 0; i < 5; i++) {
        cout << "kanal " << i+1 << ": ";
        for (double v : normPress[i]) {
            if (v > 0.9) cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<double> sumVec(sum, sum + 5);
    sort(sumVec.begin(), sumVec.end());
    
    cout << *max_element(sumVec.begin(),sumVec.end());
    cout << endl;

    return 0;
}