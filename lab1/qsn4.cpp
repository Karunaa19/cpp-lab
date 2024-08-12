/* Given that an EMPLOYEE class contains following members:
data members: Employee number, Employee name, Basic, DA, IT, Net Salary
and print data members. Write a C++ program to read the data of N employee
and compute Net salary of each employee (DA=52% of Basic and Income Tax
(IT) =30% of the gross salary) . */

#include<iostream>
using namespace std;

class Employee {
    private:
        int empNo;
        char empName[20];
        float basic, da, it, netSalary;

    public:
        void getInput() {
            cout << "Enter Employee Number: ";
            cin >> empNo;
            cout << "Enter Employee Name: ";
            cin >> empName;
            cout << "Enter Basic Salary: ";
            cin >> basic;
        }

        void calculateSalary() {
            da = 0.52 * basic;
            float grossSalary = basic + da;
            it = 0.30 * grossSalary;
            netSalary = grossSalary - it;
        }

        void display() {
            cout << "Employee Number: " << empNo << "\n";
            cout << "Employee Name: " << empName << "\n";
            cout << "Basic Salary: " << basic << "\n";
            cout << "DA: " << da << "\n";
            cout << "IT: " << it << "\n";
            cout << "Net Salary: " << netSalary << "\n";
        }
};

int main() {
    Employee emp[100];
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter data for Employee " << i + 1 << ":" << "\n";
        emp[i].getInput();
        emp[i].calculateSalary();
    }

    for(int i = 0; i < n; i++) {
        cout << "Employee " << i + 1 << " details:" <<"\n";
        emp[i].display();
    }

    return 0;
}