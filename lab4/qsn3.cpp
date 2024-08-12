/*Modify Q.2 to add base class sales that holds an array of three //multiple inheritance
floats so that it can record the dollar sales of a particular 
publication for the last three months. Include getdata() function to 
get three Sales amount from the user and a putdata() function to 
display sales figures. Alter the book and tape classes so they are 
derived from both publication and sales. An object of class book or 
tape should input and output sales data along with its other data.*/

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

class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore(); 
    }
    
    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();
        Sales::getdata();
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        cin.ignore();
        Sales::getdata();
    }
    
    void putdata() const {
        Publication::putdata();
        cout << "Playing Time (minutes): " << playingTime << endl;
        Sales::putdata();
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
