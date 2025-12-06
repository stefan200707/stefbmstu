#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

struct Library {
    vector<Book> books;
    int count;
};

int findBookByTitle(const Library& lib, const string& title) {
    for (int i = 0; i < lib.books.size(); i++) {
        if (lib.books[i].title == title) {
            return i;
        }
    }
    return -1;
}

int main() {
    Library lib;
    lib.count = 0;
    int choice;
    
    do {
        cout << "\n1. Добавить книгу" << endl;
        cout << "2. Удалить книгу" << endl;
        cout << "3. Найти книгу по автору" << endl;
        cout << "4. Показать все книги" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            Book b;
            cout << "Название: ";
            getline(cin, b.title);
            cout << "Автор: ";
            getline(cin, b.author);
            cout << "Год: ";
            cin >> b.year;
            cin.ignore();
            cout << "Жанр: ";
            getline(cin, b.genre);
            
            lib.books.push_back(b);
            lib.count++;
            cout << "Книга добавлена" << endl;
        }
        
        else if (choice == 2) {
            string title;
            cout << "Название книги для удаления: ";
            getline(cin, title);
            
            int index = findBookByTitle(lib, title);
            if (index != -1) {
                lib.books.erase(lib.books.begin() + index);
                lib.count--;
                cout << "Книга удалена" << endl;
            } else {
                cout << "Книга не найдена" << endl;
            }
        }
        
        else if (choice == 3) {
            string author;
            cout << "Автор для поиска: ";
            getline(cin, author);
            
            bool found = false;
            for (int i = 0; i < lib.books.size(); i++) {
                if (lib.books[i].author == author) {
                    cout << lib.books[i].title << " "
                         << lib.books[i].author << " "
                         << lib.books[i].year << " "
                         << lib.books[i].genre << endl;
                    found = true;
                }
            }
            
            if (!found) {
                cout << "Книги не найдены" << endl;
            }
        }
        
        else if (choice == 4) {
            cout << "\nСписок книг:" << endl;
            for (int i = 0; i < lib.books.size(); i++) {
                cout << lib.books[i].title << " "
                     << lib.books[i].author << " "
                     << lib.books[i].year << " "
                     << lib.books[i].genre << endl;
            }
        }
        
    } while (choice != 0);
    
    return 0;
}