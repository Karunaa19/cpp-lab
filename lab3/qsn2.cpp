/* 2. Program to convert Polar Coordinate to Cartesian.*/
#include<iostream>
#include<cmath>
#define PI 3.141592
using namespace std;

class polar{
    float radius, ang;
    public:
        polar(float r, float a){
            radius = r;
            ang = PI * a / 180;
        }

        float getRadius(){
            return radius;
        }

        float getAngle(){
            return ang;
        }
};

class cartesian{
    int x, y;
    public:
        cartesian(){}
        cartesian(polar p){
            float r = p.getRadius();
            float a = p.getAngle();
            x = r * cos(a);
            y = r * sin(a);
        }
        void show(){
            cout << "X: " << x << "\tY: " << y;
        }
};

int main(){

    float r, a;
    cout<<"Enter radius and angle: ";
    cin>>r>>a;
    polar p(r,a); 
    cartesian c=p;
    c.show();

    return 0;
}