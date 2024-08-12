  /* To write a C++ program to swap two private data members using friend 
functions.*/
#include <iostream>
using namespace std;

class Class2; 

class Class1 {
private:
    int value1;

public:
    void getNum() {
        cin >> value1;
    }

    void display() {
        cout << "Class1 value: " << value1 << endl;
    }

    friend void swapValues(Class1 &c1, Class2 &c2);
};

class Class2 {
private:
    int value2;

public:
    void getNum() {
        cin >> value2;
    }

    void display() {
        cout << "Class2 value: " << value2 << endl;
    }

    friend void swapValues(Class1 &c1, Class2 &c2);
};

void swapValues(Class1 &c1, Class2 &c2) {
    int temp = c1.value1;
    c1.value1 = c2.value2;
    c2.value2 = temp;
}

int main() {
    Class1 obj1;
    Class2 obj2;

    cout << "Enter value for Class1: ";
    obj1.getNum();

    cout << "Enter value for Class2: ";
    obj2.getNum();

    cout << "Before swapping:" << endl;
    obj1.display();
    obj2.display();

    swapValues(obj1, obj2);

    cout << "After swapping:" << endl;
    obj1.display();
    obj2.display();

    return 0;
}
