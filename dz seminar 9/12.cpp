#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
int main() {
    vector<string> logs = {
    "INFO: Start",
    "ERROR: Disk failure",
    "WARNING: Low memory",
    "ERROR: Disk failure",
    "INFO: Stop"
    };
    for (string x : logs) {
        std::cout << x << " "; 
    }
    cout << endl;
    shared_ptr<vector<string>> pLogs = make_shared<vector<string>>(logs);
    vector<string> errors;
    for_each(pLogs->begin(), pLogs->end(), [&errors](const string& line) { 
        if (line.find("error") != string::npos || line.find("ERROR") != string::npos) {
            errors.push_back(line);
        }
    });
    auto del = unique(errors.begin(),errors.end());
    errors.erase(del, errors.end());
    for (string x : errors) {
        std::cout << x << " "; 
    }
    cout << endl;
    return 0;
}