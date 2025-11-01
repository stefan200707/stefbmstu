#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Command {
    string name;
    int value;
};
void parseCommand(const char* input, vector<Command>& buffer) {
    const char* name_start = input; 
    const char* ptr = input;
    
    while (*ptr != ' ' and *ptr != '\0') {
        ptr++;
    }

    string name(name_start, ptr - name_start);
    
    int value = 0;
    if (*ptr == ' ') {
        ptr++;
        if (*ptr != '\0') {
            value = stoi(string(ptr));
        }
    }
    
    Command cmd;
    cmd.name = name;
    cmd.value = value;
    buffer.push_back(cmd);
}



int main() {
    vector<Command> buffer;
    char input[100];
    cin.getline(input,100);
    parseCommand(input,buffer);
    for (const auto& command : buffer) {
        cout << "Command: " << command.name << ", Value: " << command.value << endl;
    }
    return 0;
}