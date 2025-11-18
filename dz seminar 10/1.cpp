#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ifstream inFile("input.txt");
    if (inFile.is_open()) {
        string line;
        while(getline(inFile,line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << inFile.fail() << endl;
    }
    return 0;
}