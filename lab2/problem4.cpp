/* Create a class called 'TIME' that has- three integer data members for hours, minutes and seconds- constructor to initialize the
 object to zero- constructor to initialize the object to some constant value- overload +,- to add and subtract two TIME 
 objects- overload > function to compare two time- member function to display time in HH:MM:SS forma*/
#include <iostream>
using namespace std;

class Time {
    int hour;
    int min;
    int sec;
public:
    Time() {
        hour = 0;
        min = 0;
        sec = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
    }

    void display() const {
        cout << "Time: " << hour << ":" << min << ":" << sec << endl;
    }

    Time operator+(const Time &o) const {
        Time t;
        t.hour = hour + o.hour;
        t.min = min + o.min;
        t.sec = sec + o.sec;

        t.min += t.sec / 60;
        t.sec %= 60;
        t.hour += t.min / 60;
        t.min %= 60;
        return t;
    }

    Time operator-(const Time &o) const {
        Time t;
        int totalSec1 = hour * 3600 + min * 60 + sec;
        int totalSec2 = o.hour * 3600 + o.min * 60 + o.sec;
        int totalSecDiff = totalSec1 - totalSec2;

        if (totalSecDiff < 0) {
            totalSecDiff = -totalSecDiff; 
        }

        t.hour = totalSecDiff / 3600;
        totalSecDiff %= 3600;
        t.min = totalSecDiff / 60;
        t.sec = totalSecDiff % 60;

        return t;
    }

    bool operator>(const Time &o) const {
        if (hour > o.hour)
            return true;
        if (hour == o.hour && min > o.min)
            return true;
        if (hour == o.hour && min == o.min && sec > o.sec)
            return true;

        return false;
    }
};

int main() {
    int h1, m1, s1;
    int h2, m2, s2;

    // Input for t1
    cout << "Enter hours, minutes, and seconds for t1: ";
    cin >> h1 >> m1 >> s1;

    // Input for t2
    cout << "Enter hours, minutes, and seconds for t2: ";
    cin >> h2 >> m2 >> s2;

    Time t1(h1, m1, s1), t2(h2, m2, s2), t;

    cout << "\nAddition:" << endl;
    t = t1 + t2;
    t.display();

    cout << "\nSubtraction:" << endl;
    t = t1 - t2;
    t.display();

    cout << "\nComparison (t1 > t2): ";
    if (t1 > t2)
        cout << "true";
    else
        cout << "false";

    return 0;
}


