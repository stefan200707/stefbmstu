#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    ifstream text("config.txt");
    
    if (!text.is_open()) {
        cout << "Error: Cannot open config.txt" << endl;
        return 0;
    }
    
    string search_key;
    cout << "Enter key to search (format key=value): ";
    getline(cin, search_key);
    
    size_t pos2 = search_key.find('=');
    
    string key_input = search_key.substr(0, pos2+1);
    string value_input = search_key.substr(pos2 + 1);
    
    cout << "Searching for: " << key_input << value_input << endl;
    
    string line;    
    vector<string> res;
    
    while (getline(text, line)) {
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            size_t pos = word.find('=');
            if (pos != string::npos) {
                string key_file = word.substr(0, pos+1);
                string value_file = word.substr(pos + 1);                
                if (key_input == key_file) {
                    value_file = value_input;
                    word = key_file + value_file;
                    res.push_back(word);
                }
                else {
                    res.push_back(word);
                }
            }
        }
    }
    text.close();
    ofstream out_file("config.txt");
    if (!out_file.is_open()) {
        cout << "Error opening file for writing" << endl;
        return 1;
    }
    
    for (const auto& l : res) {
        out_file << l << endl;
    }
    out_file.close();
    ifstream readme("config.txt");
    string l;
    while (getline(readme,l)) {
        cout << l << endl;
    }
    return 0;
}