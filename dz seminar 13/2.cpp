#include <iostream>
#include <queue>
using namespace std;

void addToQueue(queue<string>& queue, const string& person) {
    queue.push(person);
}
void processQueue(queue<string>& queue) {
    if (!queue.empty()) {
        cout << "Обрабатывается следующее событие: " << queue.front() << endl;
        queue.pop();
    }
    else{
        cout << "Очередь пуста" << endl;
    }
}
int main() {
    queue<string> queue;
    int n = 0;
    cout << "Введите количество дробавляемых событий, а затем сами события: " << endl;
    cin >> n;
    cin.ignore();
    string person;
    while (n != 0) {
        getline(cin,person);
        addToQueue(queue,person);
        n--;
    }
    processQueue(queue);
}