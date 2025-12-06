#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    
    ofstream file("products.csv");
    file << "id,name,category,price,quantity\n";
    
    const char* categories[] = {"Электроника", "Одежда", "Книги", "Продукты", "Спорт"};
    
    for (int i = 1; i <= 20; ++i) {
        double price = 100 + (rand() % 9901);
        int quantity = 1 + (rand() % 100);
        const char* category = categories[rand() % 5];
        
        file << i << ",Товар_" << i << "," << category << ","
             << fixed << setprecision(2) << price << "," << quantity << "\n";
    }
    
    file.close();
    
    ifstream check("products.csv");
    int lines = 0;
    string line;
    while (getline(check, line)) lines++;
    
    cout << "Создано записей: " << (lines - 1) << endl;
    
    return 0;
}