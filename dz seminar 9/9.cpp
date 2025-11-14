#include <memory>
#include <iostream>
using namespace std;

void processA(std::shared_ptr<std::vector<int>> buf) {
    for (int i = 0; i < 10; i++) {
        (*buf)[i] += 1;
    }
    for (int i = 0; i < 10; i++) {
        cout << (*buf)[i] << " ";
    }
    cout << endl;
}
void processB(std::shared_ptr<std::vector<int>> buf) {
    for (size_t i = 0; i < buf -> size(); i++) {
        (*buf)[i] *= 2;
    }
    for (int i = 0; i < 10; i++) {
        cout << (*buf)[i] << " ";
    }
    cout << endl;
}

int main() {
    shared_ptr<vector<int>> buffer = make_shared<vector<int>>();
    for (int i = 0; i < 10; i++) {
        buffer -> push_back(i+1);
    }
    processA(buffer);
    processB(buffer);
    return 0;
}






