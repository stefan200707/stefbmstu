#include <iostream>
#include <memory>
using namespace std;
int main() {
    int n;
    cin >> n;
    unique_ptr<int[]> arr = make_unique<int[]>(n);    
    for (int i = 0; i < n; ++i) {
        arr[i] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
