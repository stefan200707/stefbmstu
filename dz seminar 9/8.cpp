#include <memory>
#include <iostream>
using namespace std;
int main() {
    unique_ptr<double[]> temperature = make_unique<double[]>(10);
    unique_ptr<double[]> pressure = make_unique<double[]>(10);
    unique_ptr<double[]> vlaga = make_unique<double[]>(10);
    double sumt = 0;
    double sump = 0;
    double sumv = 0;

    for (int i = 0; i < 10; i++) {
        cin >> temperature[i];
        cin >> pressure[i];
        cin >> vlaga[i];
        sumt += temperature[i];
        sump += pressure[i];
        sumv += vlaga[i];
    }
    cout << sumt / 10. << endl;
    cout << sump / 10. << endl;
    cout << sumv / 10. << endl;
    return 0;
}