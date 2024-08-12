/* 1. Program to convert Nepalese Currency (Rupees and Paisa) to US 
Currency (Dollar and Cents). (Rs. 98.51=1$)*/
#include <iostream>
using namespace std;

int main() {
    float nepaleseRupees, nepalesePaisa, USD, usCents;

    cout << "Enter Nepalese Rupees: ";
    cin >> nepaleseRupees;

    cout << "Enter Nepalese Paisa: ";
    cin >> nepalesePaisa;

    float totalNepaleseRupees = nepaleseRupees + (nepalesePaisa / 100);
   USD = totalNepaleseRupees / 98.51;

    int USDOnly = (int)USD;
    usCents = (USD - USDOnly) * 100;

    cout << "US Dollars: " << USDOnly << "." << (int)usCents<<"$" << endl;

    return 0;
}

