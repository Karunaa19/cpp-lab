/* To write a C++ program to overload all relational operators to compare 
US currency with Nepalese currency. Use conversion rate $1=NRs 
101.36(Note: make two classes to represent each currency*/

#include<iostream>
using namespace std;
class dollars;
class rupees{
    float amount;

    public:
        rupees(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }

        friend bool operator>(rupees, dollars);
        friend bool operator<(rupees, dollars);
        friend bool operator>=(rupees, dollars);
        friend bool operator<=(rupees, dollars);
        friend bool operator==(rupees, dollars);
        friend bool operator!=(rupees, dollars);       
};

class dollars{
    float amount;

    public:
        dollars(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }
        friend bool operator>(rupees, dollars);
        friend bool operator<(rupees, dollars);
        friend bool operator>=(rupees, dollars);
        friend bool operator<=(rupees, dollars);
        friend bool operator==(rupees, dollars);
        friend bool operator!=(rupees, dollars);
};

bool operator>(rupees r, dollars d){
    return (r.amount > d.amount * 101.36);
}
bool operator<(rupees r, dollars d){
    return (r.amount < d.amount * 101.36);
}
bool operator>=(rupees r, dollars d){
    return (r.amount >= d.amount * 101.36);
}
bool operator<=(rupees r, dollars d){
    return (r.amount <= d.amount * 101.36);
}
bool operator==(rupees r, dollars d){
    return (r.amount == d.amount * 101.36);
}
bool operator!=(rupees r, dollars d){
    return (r.amount != d.amount * 101.36);
}



int main(){
    float r, d;
    cout << "Enter amount in Nepali Rupees: ";
    cin >> r;
    cout << "Enter amount in US Dollars: ";
    cin >> d;

    rupees r1(r);
    dollars d1(d);
    
    cout << "\nComparisons:\n";
    
    cout << "Rupees > Dollars: " << (r1 > d1) << endl;
    cout << "Rupees < Dollars: " << (r1 < d1) << endl;
    cout << "Rupees >= Dollars: " << (r1 >= d1) << endl;
    cout << "Rupees <= Dollars: " << (r1 <= d1) << endl;
    cout << "Rupees == Dollars: " << (r1 == d1) << endl;
    cout << "Rupees != Dollars: " << (r1 != d1) << endl;

    return 0;
}
