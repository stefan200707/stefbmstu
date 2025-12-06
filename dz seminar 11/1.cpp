#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    char keyword[100];
    cin.getline(keyword, 100);
    
    ifstream text("book.txt");
    
    if (!text.is_open()) {
        cout << "Error" << endl;
        return 0;
    }
    
    string line;
    vector<pair<int, int>> res;
    int lineNumber = 0;
    
    while (getline(text, line)) {
        lineNumber++;
        stringstream ss(line);
        string word;
        int position = 0;
        
        while (ss >> word) {
            position++;
            if (word == keyword) {
                res.push_back(make_pair(lineNumber, position));
            }
        }
    }
    
    text.close();
    
    if (res.empty()) {
        cout << "Keyword '" << keyword << "' not found." << endl;
    } else {
        cout << "Found " << res.size() << " occurrences:" << endl;
        for (const auto& entry : res) {
            cout << "Line " << entry.first << ", position " << entry.second << endl;
        }
    }
    
    return 0;
}