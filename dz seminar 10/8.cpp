#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream readFil1("file1.txt");
    ifstream readFil2("file2.txt");
    string line;
    string lime;
    while (getline(readFil1,line)) {
        getline(readFil2,lime);
        if (line != lime) {
            cout << "Файлы различаются" << endl;
            return 0;
        }
    }
    cout << "Файлы идентичны" << endl;
    return 0;
}