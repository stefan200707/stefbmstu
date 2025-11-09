#include <iostream>
using namespace std;
void swapPointers(int **a, int **b) {
    int *t = *b;
    *b = *a;
    *a = t;
}
int main() {
    int x, y;
    cin >> x >> y;
    int *p1 = &x, *p2 = &y;
    swapPointers(&p1,&p2);
    cout << *p1 << " " << *p2 << endl;
    return 0;
}