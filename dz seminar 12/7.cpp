#include <iostream>
#include <vector>
using namespace std;

union Shape {
    struct {
        int r;
    } circle;
    
    struct {
        int length;
        int width;
    } rectangle;
};

int main() {
    cout << "Выберите фигуру (1 - круг, 2 - прямоугольник): ";
    int c;
    cin >> c;
    
    Shape sh;
    
    if (c == 1) {
        cout << "Введите радиус круга: ";
        cin >> sh.circle.r;
        cout << "Площадь круга: " << 3.14 * sh.circle.r * sh.circle.r << endl;
    }
    else if (c == 2) {
        cout << "Введите длину прямоугольника: ";
        cin >> sh.rectangle.length;
        cout << "Введите ширину прямоугольника: ";
        cin >> sh.rectangle.width;
        cout << "Площадь прямоугольника: " << sh.rectangle.length * sh.rectangle.width << endl;
    }
    else {
        cout << "Неверный выбор" << endl;
    }
    
    return 0;
}