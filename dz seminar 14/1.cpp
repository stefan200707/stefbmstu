#include <iostream>
#include <string>
using namespace std;
class Publication {
    protected: string publicname;
};
class Book : public Publication {
private:
    string author;
    int date;
public:
    Book(string name, string auth, int dat) {
        publicname = name;
        author = auth;
        date = dat;
    }
    void displayinfo() {
        cout << "Название: " << publicname << ", " << "Автор: " << author << ", Год выпуска: " << date << endl;
    }
};
int main() {
    Book book("Преступление и наказание","Фёдор Достаевский",1866);
    book.displayinfo();

    return 0;
}