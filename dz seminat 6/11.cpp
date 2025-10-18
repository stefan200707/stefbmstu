#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char str[MAX_SIZE];
    char sequences[MAX_SIZE][MAX_SIZE];
    int count = 0;
    
    cin.getline(str, MAX_SIZE);
    
    int n;
    cin >> n;
    
    int len = strlen(str);
    
    for (int i = 0; i < len - n + 1; i++) {
        char temp[MAX_SIZE];
        
        for (int j = 0; j < n; j++) {
            temp[j] = str[i + j];
        }
        temp[n] = '\0';
        
        int f = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(sequences[j], temp) == 0) {
                f = 1; 
                break;
            }
        }
        
        if (f == 0) {
            strcpy(sequences[count], temp);
            count++;
        }
    }
    
    for (int i = 0; i < count; i++) {
        cout << sequences[i] << " ";
    }
    
    return 0;
}