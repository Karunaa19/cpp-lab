// WAP to categorize employees based on designation using static data members.

#include<iostream>
#include<string.h>
using namespace std;

class Employee {
    private:
        int id;
        char name[20];
        char designation[10];
        static int managerCount;
        static int engineerCount;

    public:
        void setData() {
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Designation (MANAGER/ENGINEER): ";
            cin >> designation;

            if(strcmp(designation, "MANAGER") == 0) {
                managerCount++;
            } else if(strcmp(designation, "ENGINEER") == 0) {
                engineerCount++;
            }
        }

        static void displayCount(int n) {
            cout << "Total Managers: " << managerCount << "\n";
            cout << "Total Engineers: " << engineerCount << "\n";
            cout << "Total Employees: " << n << "\n";
        }
};

int Employee::managerCount = 0;
int Employee::engineerCount = 0;

int main() {
    Employee emp[100];
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        emp[i].setData();
    }

    Employee::displayCount(n);

    return 0;
}