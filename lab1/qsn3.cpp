/*Write a program that checks the order of a medicine from a pharmacy store.
The program should read the order quantity and the medicine quantity in the
store. When the order quantity is more than the store quantity, your
program should display the message “No enough quantity”. When the order
quantity is less than the store quantity, you have to check that the order
quantity must be not more than 16 except there is more than 40 items in the
store. The messages that will be displayed in that cases are “Your order is
accepted” OR “You cannot order more than 16 item*/

#include<iostream>
using namespace std;

int isValidOrder(int order_quantity, int store_quantity) {
    if (order_quantity > store_quantity) {
        return 1; 
    }
    else if (order_quantity <= 16) {
        if (store_quantity >= 40) {
            return 2; 
        }
        else {
            return 3; 
        }
    }
    else {
        return 3; 
    }
}


void displayResult(int result) {
    switch (result) {
        case 1:
            cout << "No enough quantity" << endl;
            break;
        case 2:
            cout << "Your order is accepted" << endl;
            break;
        case 3:
            cout << "You cannot order more than 16 items" << endl;
            break;
    }
}

int main() {
    int order_quantity, store_quantity;
    cout << "Enter the order quantity: ";
    cin >> order_quantity;
    cout << "Enter the medicine quantity in the store: ";
    cin >> store_quantity;
    int result = isValidOrder(order_quantity, store_quantity);
    displayResult(result);
    return 0;
}