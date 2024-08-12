/* 3. Program to convert Cartesian coordinate to Polar.*/
#include <iostream>
#include <cmath>

using namespace std;

class polar {
    private:
        float rad, ang;

    public:
        polar() : rad(0), ang(0) {}
        polar(float r, float a) : rad(r), ang(a) {}

        void show() const {
            cout << "Radius: " << rad << ", Angle: " << ang << " radians" << endl;
        }
};

class cartesian {
    private:
        float x, y;

    public:
        cartesian() : x(0), y(0) {}
        cartesian(float x, float y) : x(x), y(y) {}

        operator polar()  {
            float r = sqrt(x * x + y * y);
            float a = atan2(y, x);

            return polar(r, a);
        }
};

int main() {
    float x, y;
    cout << "Enter X and Y of Cartesian coordinate: " << endl;
    cin >> x >> y;
    cartesian c(x, y);
    polar p = c;

    p.show();
    return 0;
}
