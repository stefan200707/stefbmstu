#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // для rand() и srand()
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    vector <int> nums;
    int n = 50;
    for (int i = 0; i < n; ++i) {
        nums.push_back(rand() % 180);
    }
    nums.erase(remove_if(nums.begin(),nums.end(), [](int n){ return n < 0; }), nums.end());
    for (int x : nums) cout << x << " ";
    return 0;
}