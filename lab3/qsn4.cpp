// /*4. Program to convert time (hour, minute and second) in 24-hr format to 
// 12-hr format.*/
#include<iostream>

using namespace std;


class TwentyFour{
    int hr, min, sec;

    public:
        TwentyFour(){}
        TwentyFour(int  h, int m, int s) {
            hr=h;
            min=m;
            sec=s;
        } 

        int getH(){
            return hr;
        }

        int getM(){
            return min;
        }
        
        int getS(){
            return sec;
        }

        void show(){
            if(hr<10){
                cout<<"0"<<hr<<": "<<endl;
            }
            cout << (hr < 10 ? "0" : "") << hr << ":"
            << (min < 10 ? "0" : "") << min << ":"
            << (sec < 10 ? "0" : "") << sec << endl;
        }
};

class Twelve{
    int hr, min, sec;
    string meridian;

    public:
    Twelve() : hr(0), min(0), sec(0), meridian("AM") {}
    Twelve(int h, int m, int s) : hr(h), min(m), sec(s) {
        if (h >= 12) {
            meridian = "PM";
            if (h > 12) hr -= 12;
        } else {
            meridian = "AM";
            if (h == 0) hr = 12; // Midnight case
        }
    }

    Twelve( TwentyFour &t) {
    int hour24 = t.getH();
    min = t.getM();
    sec = t.getS();

    if (hour24 == 0) {
        hr = 12;
        meridian = "AM";
    } else if (hour24 < 12) {
        hr = hour24; 
        meridian = "AM";
    } else if (hour24 == 12) {
        hr = 12; 
        meridian = "PM";
    } else {
        hr = hour24 - 12;
        meridian = "PM";
    }
}
        void show(){
            cout << (hr < 10 ? "0" : "") << hr << ":"
            << (min < 10 ? "0" : "") << min << ":"
            << (sec < 10 ? "0" : "") << sec << " "
            << meridian << endl;
        }
     
};

int main(){
    int hr,min,sec;
    cout<<"Enter hour minute and second respectively:"<<endl;
    cin>>hr>>min>>sec;
    TwentyFour t24(hr, min, sec);
    Twelve t12;
    t12 = t24;

    cout << "12 hours format: ";
    t24.show();
    cout << "24 hours format: ";
    t12.show();

    return 0;
}

