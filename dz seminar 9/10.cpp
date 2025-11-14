#include <memory>
#include <iostream>
using namespace std;

unique_ptr<int[]> createArray(int n) {
    unique_ptr<int[]> arr = make_unique<int[]>(n);
    for (int i = 0;i < n;i++) {
        arr[i] += i+1;
    }
    return arr;
}
int main() {
    int n;
    cin >> n;
    unique_ptr<int[]> arr = createArray(n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}