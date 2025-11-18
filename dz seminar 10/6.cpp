#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ofstream EX6("output.txt");
    string line;
    while(getline(cin,line)) {
        EX6 << line << "\n";
        if (line == "\n" or line == "") break;
    }
    return 0;
}