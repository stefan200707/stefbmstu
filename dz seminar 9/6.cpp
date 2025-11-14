#include <iostream>
#include <memory>

int main() {
    auto a = std::make_shared<int>(100);
    auto b = a; 
    auto c = a;
    
    std::cout << "Значение: " << *a << std::endl;
    std::cout << "Счётчик ссылок: " << a.use_count() << std::endl;

    a.reset(); 
    std::cout << "После reset(): " << b.use_count() << std::endl;
}
