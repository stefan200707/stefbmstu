#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string line;
        int cnt = 0;
        while(getline(inFile,line)) {
            cnt++;
        }
        inFile.close();
        cout << cnt << endl;
    }
    else {
        cout << inFile.fail() << endl;
    }
    return 0;
}