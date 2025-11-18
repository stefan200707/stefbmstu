#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    ifstream inFile("input.txt");
    if (inFile.is_open()) {
        string line;
        int cnt = 0;
        char ch;
        while(inFile.get(ch)) {
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