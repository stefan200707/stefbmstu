#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n; 
    
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int *begin = &vec[0];
    int *end = begin + n;  
    int sum = 0;
    
    for (int *p = begin; p != end; ++p) {
        sum += *p;
    }
    
    cout << sum << endl;
    return 0;
}