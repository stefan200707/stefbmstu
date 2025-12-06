#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};
int main() {
    ifstream file("products.csv");
    string line;
    vector<Product> products;
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;
        
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        
        if (fields.size() >= 5) {
            Product p;
            p.id = stoi(fields[0]);        
            p.name = fields[1];
            p.category = fields[2];      
            p.price = stod(fields[3]);      
            p.quantity = stoi(fields[4]);   
            
            products.push_back(p);
        }
    }
    auto price_asc = [](const Product& a, const Product& b) {
        return a.price < b.price;
        };
    
    return 0;
}