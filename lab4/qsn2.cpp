/*Create a class publication that stores the title and price of a 
publication. From this class derive two classes:book, which adds a 
page count and tape, which adds a playing time in minutes. Each of 
these three classes should have getdata() function to get its data 
from the user at the keyboard and putdata() function to display its 
data.*/
//hierarchical 
#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }
    
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore(); // To ignore the newline character after entering the page count
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        cin.ignore();
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Playing Time (minutes): " << playingTime << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter data for book:" << endl;
    book.getdata();
    cout << "Enter data for tape:" << endl;
    tape.getdata();

    cout << "\nDisplaying book data:" << endl;
    book.putdata();
    cout << "\nDisplaying tape data:" << endl;
    tape.putdata();

    return 0;
}
