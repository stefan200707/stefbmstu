#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    using namespace std;

    const string INPUT_FILENAME = "application.log";
    const string INDEX_FILENAME = "log_index.txt";
    const long long MAX_PART_SIZE = 10 * 1024 * 1024; 
    const size_t BUFFER_SIZE = 4096;
    
    ifstream inputFile(INPUT_FILENAME, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть " << INPUT_FILENAME << endl;
        return 1;
    }

    inputFile.seekg(0, ios::end);
    long long totalSize = inputFile.tellg();
    inputFile.seekg(0, ios::beg);

    if (totalSize == 0) {
        cout << "Файл пуст." << endl;
        return 0;
    }
    
    cout << "Начало разделения файла (" << totalSize << " байт)..." << endl;

    vector<string> indexEntries;
    long long currentPosition = 0;
    int partNumber = 1;
    
    vector<char> buffer(BUFFER_SIZE);

    while (currentPosition < totalSize) {
        long long targetSplitPos = currentPosition + MAX_PART_SIZE;
        long long safeEndPos;

        if (targetSplitPos >= totalSize) {
            safeEndPos = totalSize;
        } else {
            inputFile.seekg(targetSplitPos);
            char c;
            
            while (inputFile.get(c)) {
                if (c == '\n') {
                    safeEndPos = inputFile.tellg(); 
                    break;
                }
                if (inputFile.eof()) {
                    safeEndPos = totalSize;
                    break;
                }
            }
        }
        
        long long chunkSize = safeEndPos - currentPosition;
        if (chunkSize <= 0) break; 

        stringstream ss;
        ss << "log_part" << partNumber << ".txt";
        string partFilename = ss.str();
                ofstream outputFile(partFilename, ios::binary);
        if (!outputFile.is_open()) {
            cerr << "Ошибка: Не удалось создать файл части " << partFilename << endl;
            return 1;
        }

        inputFile.seekg(currentPosition);

        long long bytesRemaining = chunkSize;
        while (bytesRemaining > 0) {
            size_t bytesToRead = min((long long)BUFFER_SIZE, bytesRemaining);
            inputFile.read(buffer.data(), bytesToRead);
            outputFile.write(buffer.data(), inputFile.gcount());
            bytesRemaining -= inputFile.gcount();
        }

        outputFile.close();

        stringstream indexEntry;
        indexEntry << partFilename << " | Размер: " << chunkSize << " байт | Начало: " 
                   << currentPosition << " | Конец: " << safeEndPos;
        indexEntries.push_back(indexEntry.str());

        cout << "Создана часть: " << partFilename << " (" << chunkSize << " байт)" << endl;

        currentPosition = safeEndPos;
        partNumber++;
    }

    inputFile.close();

    ofstream indexFile(INDEX_FILENAME);
    if (!indexFile.is_open()) {
        cerr << "Ошибка: Не удалось создать файл-индекс " << INDEX_FILENAME << endl;
        return 1;
    }

    indexFile << "--- Индекс лог-файла " << INPUT_FILENAME << " ---" << endl;
    indexFile << "Общий размер: " << totalSize << " байт." << endl;
    indexFile << "Количество частей: " << indexEntries.size() << endl;
    indexFile << "---------------------------------------------------" << endl;
    
    for (const string& entry : indexEntries) {
        indexFile << entry << endl;
    }

    indexFile.close();
    cout << "\nРазделение завершено. Индекс сохранен в " << INDEX_FILENAME << endl;

    return 0;
}
