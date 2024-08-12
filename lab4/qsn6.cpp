#include <iostream>
using namespace std;

class student {
protected:
    int rn;
    char name[20];

public:
    void getstInfo() {
        cout << "Enter student roll number and name: ";
        cin >> rn >> name;
    }

    void showstInfo() {
        cout << "\nStudent roll: " << rn;
        cout << "\nStudent name: " << name << endl;
    }
};

class InternalExam : virtual public student {
protected:
    int fm[7], om[7];

public:
    void getInfo() {
        cout << "Enter full marks and obtained marks in internal exam (in pairs): " << endl;
        for (int i = 0; i < 7; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> fm[i] >> om[i];
        }
    }

    void showInfo() {
        cout << "\nInternal Exam Marks:" << endl;
        for (int i = 0; i < 7; i++) {
            cout << "Subject " << i + 1 << " - Full Marks: " << fm[i] << ", Obtained Marks: " << om[i] << endl;
        }
    }
};

class finalExam : virtual public student {
protected:
    int fm[7], om[7];

public:
    void getInfo() {
        cout << "Enter full marks and obtained marks in final exam (in pairs): " << endl;
        for (int i = 0; i < 7; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> fm[i] >> om[i];
        }
    }

    void showInfo() {
        cout << "\nFinal Exam Marks:" << endl;
        for (int i = 0; i < 7; i++) {
            cout << "Subject " << i + 1 << " - Full Marks: " << fm[i] << ", Obtained Marks: " << om[i] << endl;
        }
    }
};

class Result : public InternalExam, public finalExam {
public:
    void getInfo() {
        InternalExam::getInfo();
        finalExam::getInfo();
    }

    void showInfo() {
        InternalExam::showInfo();
        finalExam::showInfo();
        displayResult();
    }

    void displayResult() {
        int totalObtainedMarks = 0;
        int totalFullMarks = 0;
        for (int i = 0; i < 7; i++) {
            totalObtainedMarks += InternalExam::om[i] + finalExam::om[i];
            totalFullMarks += InternalExam::fm[i] + finalExam::fm[i];
        }
        cout << "\nTotal Full Marks: " << totalFullMarks << endl;
        cout << "Total Obtained Marks: " << totalObtainedMarks << endl;
    }
};

int main() {
    Result r;
    r.getstInfo();
    r.getInfo();
    r.showstInfo();
    r.showInfo();

    return 0;
}
