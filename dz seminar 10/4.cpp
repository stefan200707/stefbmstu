#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ifstream inFile("source.txt");
    ofstream outFile("copy.txt");
    if (inFile.is_open() and outFile.is_open()) {
        string line;
        int cnt = 0;
        while(getline(inFile,line)) {
            outFile << line << "\n";
        }
        inFile.close();
        outFile.close();
    }
    else {
        cout << inFile.fail() << endl;
    }
    return 0;
}