/*Create a 'DISTANCE' class with :
- feet and inches as data members
- member function to input distance
- member function to output distance
- member function to add two distance objects
Write a main function to create objects of DISTANCE class. Input two distances
and output the sum. */

#include<iostream>
using namespace std;

class DISTANCE {
int feet;
float inches;

public:
void input(){
    cout<<"Enter feet:";
    cin>>feet;
    cout<<"Enter inches";
    cin>>inches;
}

void output(){
    cout<<"The distance is: ";
    cout<<feet <<"'"<<inches <<"\"";
}

DISTANCE add(DISTANCE d1){
    DISTANCE sum;
    sum.feet = feet + d1.feet;
    sum.inches = inches + d1.inches;
    while (sum.inches>=12){
        sum.feet ++;
        sum.inches -= 12;
    }
    return sum;
}
};

int main(){
    DISTANCE d1, d2, sum;
    cout<<"Enter the first distance: \n";
    d1.input();
    cout<<"Enter the second distance: \n";
    d2.input();
    sum = d1.add(d2);
    sum.output();
    return 0;
}