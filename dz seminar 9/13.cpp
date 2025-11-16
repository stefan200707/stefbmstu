#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    unique_ptr<string> part1 = make_unique<string>("Sensor data:");
    unique_ptr<string> part2 = make_unique<string>("Voltage stable.");
    unique_ptr<string> part3 = make_unique<string>("System nominal.");
    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));
    
    string result1;
    for_each(reportParts.begin(), reportParts.end(), 
        [&result1](const unique_ptr<string>& part) {
            result1 += *part + " ";
        });
    
    auto countWord = [](const string& text, const string& targetWord) {
        int count = 0;
        size_t pos = 0;
        
        while ((pos = text.find(targetWord, pos)) != string::npos) {
            count++;
            pos += targetWord.length(); 
        }
        return count;
    };
    
    int wordCount = countWord(result1, "data");
    cout << "The word 'data' appears " << wordCount << " times" << endl;
    
    cout << "Full text: " << result1 << endl;
    
    cout << endl;
    return 0;
}