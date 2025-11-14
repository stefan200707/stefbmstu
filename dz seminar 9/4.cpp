#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr1 = make_unique<int>(42);
    unique_ptr<int> ptr2 = std::move(ptr1);

    if (!ptr1)
        cout << "ptr1 теперь null\n";

    cout << "ptr2 указывает на: " << *ptr2 << endl;

    return 0;
}
