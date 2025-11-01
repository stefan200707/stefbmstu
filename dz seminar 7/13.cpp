#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

void parseTelemetry(const char* data) {
    int k = 0;
    for (const char *ptr = data; *ptr != '\0'; ptr++) {
        if (*ptr == ';') k++;
    }
    k++; 
    char words[100][100];
    int j = 0;
    int word_index = 0; 
    
    for (const char *ptr = data; *ptr != '\0'; ptr++) {
        if (*ptr != ';') {
            if (word_index < 99) { 
                words[j][word_index++] = *ptr;
            }
        } else {
            words[j][word_index] = '\0'; 
            j++;
            word_index = 0;
            if (j >= 100) break;
        }
    }
    
    if (word_index > 0 && j < 100) {
        words[j][word_index] = '\0';
        j++;
    }
    
    for (int i = 0; i < j; i++) {
        cout << words[i] << endl;
    }
}

int main() {
    char telemetry_data[100];
    cin.getline(telemetry_data,100);
    parseTelemetry(telemetry_data);
    return 0;
}