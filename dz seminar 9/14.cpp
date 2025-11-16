#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    unique_ptr<double[]> matrix(new double[N * M]);
    
    for (int i = 0; i < N * M; i++) {
        cin >> matrix[i];
    }
    
    auto sum = [N, M](unique_ptr<double[]>& mat) {
        vector<double> z;
        
        for (int j = 0; j < M; j++) {
            double total = 0;
            for (int i = 0; i < N; i++) {
                total += mat[i * M + j];
            }
            z.push_back(total);
        }
        return z;
    };
    
    vector<double> zx = sum(matrix);
    
    cout << "Column sums: ";
    for (double val : zx) {
        cout << val << " ";
    }
    cout << endl;

    auto ind = [](vector<double> xx) {
        int size = xx.size();
        int i = 0;
        double maxt = xx[0];
        for (int d = 0; d < size; d++) {
            if (maxt < xx[d]) {
                maxt = xx[d];
                i = d;
            }
        }
        return i+1;
    };
    cout << ind(zx) << endl;
    
    return 0;
}