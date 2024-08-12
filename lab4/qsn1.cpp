/*Assume class person stores the Name, Age and ID, class employee multilevel inheritance
stores the designation, basic salary, total overtime(hr) in a month 
and hourly rate and class computedSalary stores the total salary of 
the employee. Implement above concept using appropriate inheritance.*/

#include <iostream>
#include <string>

using namespace std;
class Person {
protected:
    string name;
    int age;
    string id;

public:
    Person(string n, int a, string i) {
        name = n;
        age = a;
        id = i;
    }

    void displayPersonInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nID: " << id << endl;
    }
};
class Employee : public Person {
protected:
    string designation;
    double basicSalary;
    float totalOvertimeHours;
    float hourlyRate;

public:
    Employee(string n, int a, string i, string d, double bs, double toh, double hr)
        : Person(n, a, i) {
        designation = d;
        basicSalary = bs;
        totalOvertimeHours = toh;
        hourlyRate = hr;
    }

    void displayEmployeeInfo() {
        displayPersonInfo();
        cout << "Designation: " << designation << "\nBasic Salary: " << basicSalary
             << "\nTotal Overtime Hours: " << totalOvertimeHours << "\nHourly Rate: " << hourlyRate << endl;
    }
};

class ComputedSalary : public Employee {
public:
    ComputedSalary(string n, int a, string i, string d, double bs, double toh, double hr)
        : Employee(n, a, i, d, bs, toh, hr) {}

    double computeTotalSalary() {
        return basicSalary + (totalOvertimeHours * hourlyRate);
    }

    void displaySalary() {
        displayEmployeeInfo();
        cout << "Total Salary: " << computeTotalSalary() << endl;
    }
};

int main() {
    string name, id, designation;
    int age;
    double basicSalary;
    float totalOvertimeHours, hourlyRate;
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Designation: ";
    cin >> designation;

    cout << "Enter Basic Salary: ";
    cin >> basicSalary;

    cout << "Enter Total Overtime Hours: ";
    cin >> totalOvertimeHours;

    cout << "Enter Hourly Rate: ";
    cin >> hourlyRate;

    ComputedSalary emp(name, age, id, designation, basicSalary, totalOvertimeHours, hourlyRate);

    emp.displaySalary();

    return 0;
}



