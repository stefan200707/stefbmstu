#include <iostream>
#include <memory>
#include <cstring>  // for strlen
#include <cctype>   // for tolower
using namespace std;

bool gla(char t) {
    t = tolower(t);
    return (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || t == 'y');
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    
    int kg = 0, ks = 0;
    size_t length = input.size();
    
    unique_ptr<char[]> gl = make_unique<char[]>(length + 1);
    unique_ptr<char[]> str = make_unique<char[]>(length + 1);
    
    int j = 0; 
    
    for (size_t i = 0; i < length; ++i) {
        str[i] = input[i];
        
        if (isalpha(str[i])) { 
            if (gla(str[i])) {
                kg++;
                gl[j++] = str[i]; 
            } else {
                ks++;
            }
        }
    }
    
    str[length] = '\0';
    gl[j] = '\0'; 
    
    cout << "Гласные: " << kg << ", Согласные: " << ks << endl;
    cout << "Гласные буквы: " << gl.get() << endl;
    
    return 0;
}