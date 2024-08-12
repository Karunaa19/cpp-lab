/*class Date 
{
        int day,month,year;
  public:
      Date();
        ~Date();
        void display(); // displays the date
        Date get(); //  accesses the date members
        void set();     // sets the date members
 };
 class Time 
{
        int hour;
        int minute;
        int second;
  public:
        Time();
        ~Time();
        void display(); // displays the time
        Time get();// accesses the time members
        void set(); // sets the time members
 };
 class DateAndTime : public Date, public Time 
{      
  public:
      void display(); // prints date and time
 };
 a. Define an instance object of class DateTime called Watch. 
b. Write a main () function that would initialize the values through the constructor
 functions, and then allows them to be reset through the set () functions.  Be sure and
 display the results following the constructor before you use the set functions.
 c. Through the use of the display () function, the time and date are to be displayed. Note
 that the display () functions in all three classes need to be defined, as well as the
 constructor and all the access functions.*/
//multiple inheritance
#include <iostream>

using namespace std;

class Date {
    int day, month, year;

public:
    Date() : day(0), month(0), year(0000) {
        cout << "Date constructor called.\n";
    }

    ~Date() {
        cout << "Date destructor called.\n";
    }

    void display() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    Date get() {
        Date temp;
        temp.day = day;
        temp.month = month;
        temp.year = year;
        return temp;
    }

    void set(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void set() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }
};

class Time {
    int hour, minute, second;

public:
    Time() : hour(0), minute(0), second(0) {
        cout << "Time constructor called.\n";
    }

    ~Time() {
        cout << "Time destructor called.\n";
    }

    void display() {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }

    Time get() {
        Time temp;
        temp.hour = hour;
        temp.minute = minute;
        temp.second = second;
        return temp;
    }

    void set(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    void set() {
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;
    }
};

class DateAndTime : public Date, public Time {
public:
    void display() {
        Date::display();
        Time::display();
    }
};

int main() {

    DateAndTime Watch;

    cout << "Initial values:\n";
    Watch.display();

    cout << "\nEnter new date values:\n";
    Watch.Date::set();
    
    cout << "\nEnter new time values:\n";
    Watch.Time::set();

    cout << "\nValues after using set() functions:\n";
    Watch.display();

    return 0;
}
