#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void printArray(int a[]) {
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int sum(int a[]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += a[i];
    }
    return total;
}

int main() {
    int numbers[] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    ofstream outfile("numbers.bin", ios::binary);
    outfile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    outfile.close();
    const int size = 10;
    int buffer[size];
    ifstream file("numbers.bin", ios::binary);
    file.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
    file.seekg(0, ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, ios::beg);
    cout << file_size << endl;
    cout << sum(buffer) << endl;
    return 0;
}