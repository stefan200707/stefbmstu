#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <vector>
using namespace std;

int main() {
    ifstream inFile("numbers.txt");
    if (inFile.is_open()) {
        string line;
        vector<int> gdt;
        while(getline(inFile,line)) {
            size_t nach = 0;
            size_t end = line.find(" ");
            while (end != string::npos) {
                string numStr = line.substr(nach, end-nach);
                if (!numStr.empty()) {
                    try {
                        gdt.push_back(stoi(numStr));
                    }
                    catch(const std::exception& e) {
                    }
                }
                nach = end + 1;
                end = line.find(" ", nach);
            }
            string lastNumStr = line.substr(nach);
            if (!lastNumStr.empty()) { 
                try {
                    gdt.push_back(stoi(lastNumStr));
                }
                catch(const std::exception& e) {
                }
            }
        }
        
        if (!gdt.empty()) { 
            auto sums = [&gdt]() {int s = 0; for (int i = 0; i < gdt.size(); i++) s+= gdt[i]; return s;};
            double sr = sums() / (double) gdt.size();
            cout << gdt.size() << " " << sums() << " " << sr << endl;
        } else {
            cout << "Нет корректных чисел для обработки" << endl;
        }
        
        inFile.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
    return 0;
}