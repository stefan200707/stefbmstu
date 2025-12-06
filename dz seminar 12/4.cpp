#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct BankAccount {
    int id;
    string name;
    int balance;
};

int findAccount(const vector<BankAccount>& accounts, int id) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    
    do {
        cout << "\n1. Добавить счет" << endl;
        cout << "2. Просмотреть счета" << endl;
        cout << "3. Пополнить счет" << endl;
        cout << "4. Снять деньги" << endl;
        cout << "5. Сохранить в файл" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            BankAccount k;
            cout << "Номер счета: ";
            cin >> k.id;
            cin.ignore();
            cout << "ФИО: ";
            getline(cin, k.name);
            cout << "Баланс: ";
            cin >> k.balance;
            accounts.push_back(k);
        }
        
        else if (choice == 2) {
            cout << "\nСписок счетов:" << endl;
            for (int i = 0; i < accounts.size(); i++) {
                cout << accounts[i].id << " "
                     << accounts[i].name << " "
                     << accounts[i].balance << endl;
            }
        }
        
        else if (choice == 3) {
            int id, sum;
            cout << "Номер счета: ";
            cin >> id;
            int index = findAccount(accounts, id);
            if (index != -1) {
                cout << "Сумма: ";
                cin >> sum;
                accounts[index].balance += sum;
                cout << "Новый баланс: " << accounts[index].balance << endl;
            } else {
                cout << "Счет не найден" << endl;
            }
        }
        
        else if (choice == 4) {
            int id, sum;
            cout << "Номер счета: ";
            cin >> id;
            int index = findAccount(accounts, id);
            if (index != -1) {
                cout << "Сумма: ";
                cin >> sum;
                if (sum <= accounts[index].balance) {
                    accounts[index].balance -= sum;
                    cout << "Новый баланс: " << accounts[index].balance << endl;
                } else {
                    cout << "Недостаточно средств" << endl;
                }
            } else {
                cout << "Счет не найден" << endl;
            }
        }
        
        else if (choice == 5) {
            ofstream File("Bank.txt");
            File << "id,name,balance\n";
            for (int i = 0; i < accounts.size(); i++) {
                File << accounts[i].id << ","
                     << accounts[i].name << ","
                     << accounts[i].balance << "\n";
            }
            File.close();
            cout << "Данные сохранены" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}