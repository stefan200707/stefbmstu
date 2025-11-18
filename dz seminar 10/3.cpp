#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <vector>
using namespace std;
int main() {
    ifstream inFile("text.txt");
    if (inFile.is_open()) {
        string line;
        vector<string> gdt;
        while(getline(inFile,line)) {
            size_t nach = 0;
            size_t end = line.find(" ");
            while (end != string::npos) {
                gdt.push_back(line.substr(nach,end-nach));
                nach = end + 1;
                end = line.find(" ",nach);
            }
            gdt.push_back(line.substr(nach));
        }
        cout << gdt.size() << endl;
        inFile.close();
    }
    else {
        cout << inFile.fail() << endl;
    }
    return 0;
}