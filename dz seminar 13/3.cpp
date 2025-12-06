#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

// Структура заказа
struct Order {
    string customerName;
    vector<string> items;
};

// Функция для добавления заказа в очередь
void addOrder(queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
}

// Функция для обработки заказа из начала очереди
void processOrder(queue<Order>& orderQueue) {
    if (!orderQueue.empty()) {
        Order currentOrder = orderQueue.front();
        
        cout << "Обрабатывается заказ клиента: " << currentOrder.customerName << endl;
        cout << "Товары в заказе:" << endl;
        
        for (int i = 0; i < currentOrder.items.size(); i++) {
            cout << "- " << currentOrder.items[i] << endl;
        }
        
        orderQueue.pop();
        cout << "Заказ обработан" << endl;
    }
    else {
        cout << "Очередь заказов пуста" << endl;
    }
}

int main() {
    queue<Order> orderQueue;
    int n = 0;
    
    cout << "Введите количество добавляемых заказов: " << endl;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        Order newOrder;
        
        cout << "Введите имя клиента для заказа " << i + 1 << ": " << endl;
        getline(cin, newOrder.customerName);
        
        int itemCount = 0;
        cout << "Введите количество товаров в заказе: " << endl;
        cin >> itemCount;
        cin.ignore();
        
        for (int j = 0; j < itemCount; j++) {
            string item;
            cout << "Введите товар " << j + 1 << ": " << endl;
            getline(cin, item);
            newOrder.items.push_back(item);
        }
        
        addOrder(orderQueue, newOrder);
    }
    
    // Обработка всех заказов
    while (!orderQueue.empty()) {
        processOrder(orderQueue);
        cout << endl;
    }
    
    // Проверка пустой очереди
    processOrder(orderQueue);
    
    return 0;
}