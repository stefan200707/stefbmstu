#include <iostream>
#include <cstring>
using namespace std;


void func(char** words) {
    const int MAX_WORDS = 10;
    int wordCount = 0;
    
    for (char* word = strtok(words[0], " "); word != nullptr; word = strtok(nullptr, " ")) {
        words[wordCount] = word;
        wordCount++;
    }

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированные слова: ";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
}

int main() {
    const int MAX_WORDS = 10;    
    char** words = new char*[MAX_WORDS];
    char* input = new char[MAX_INPUT];
    cin.getline(input, MAX_INPUT);
    
    words[0] = input;
    func(words);
    delete[] input;
    delete[] words;
    
    return 0;
}