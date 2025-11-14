#include <iostream>
#include <memory>   
#include <iomanip>  

int main() {
    int N = 5; 
    int M = 7; 

    std::unique_ptr<int[]> arr = std::make_unique<int[]>(N * M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i * M + j] = i * j;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(4) << arr[i * M + j];
        }
        std::cout << std::endl;
    }

    return 0;
}
