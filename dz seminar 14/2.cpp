#include <iostream>
#include <string>
using namespace std;
class Shape {
protected:
    int length;
};
class Rectangle : public Shape {
private:
    int width;
public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }
    int calculateArea() {
        return length * width;
    }
    int calculatePerimetr() {
        return 2 * (length + width);
    }
    void displayInfo() {
        cout << "Длина: " << length << ", " << "Ширина: " << width << ", Площадь: " << calculateArea() << ", Периметр: " << calculatePerimetr() << endl;
    }
};
int main() {
    int a, b;
    cin >> a >> b;
    Rectangle rectangle(a, b);
    rectangle.displayInfo();
    return 0;
}