#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout << "Для корректности вводите слова через пробел без запятых и др сиволов пожалуйста" << endl;
    const int maxsize = 100;
    char str[maxsize];
    char result[maxsize] = "";  
    
    cout << "Введите строку: ";
    cin.getline(str, maxsize);
    
    const char* deliv = " \t\n";
    char* word = strtok(str, deliv);
    
    if (word == nullptr) {
        cout << "Нет слов.\n";
        return 0;
    }
    
    char pod1[maxsize];
    cout << "Введите слово для замены: ";
    cin.getline(pod1, maxsize);
    
    char pod2[maxsize];
    cout << "Введите слово-замену: ";
    cin.getline(pod2, maxsize);
    
    if (strcmp(word, pod1) == 0) {
        strcat(result, pod2);
    } else {
        strcat(result, word);
    }
    
    word = strtok(nullptr, deliv);
    while (word != nullptr) {
        strcat(result, " "); 
        
        if (strcmp(word, pod1) == 0) {
            strcat(result, pod2); 
        } else {
            strcat(result, word); 
        }
        
        word = strtok(nullptr, deliv);
    }
    
    cout << "Результат: " << result << endl;
    return 0;
}