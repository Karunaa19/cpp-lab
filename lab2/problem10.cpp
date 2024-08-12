/* Modify all member operator functions to  friend function.*/
#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    friend Complex operator+(const Complex& c1, const Complex& c2) {
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }

    friend Complex operator-(const Complex& c1, const Complex& c2) {
        return Complex(c1.real - c2.real, c1.imag - c2.imag);
    }

    friend Complex operator*(const Complex& c1, const Complex& c2) {
        return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
    }

    friend Complex operator/(const Complex& c1, const Complex& c2) {
        double denominator = c2.real * c2.real + c2.imag * c2.imag;
        return Complex((c1.real * c2.real + c1.imag * c2.imag) / denominator, (c1.imag * c2.real - c1.real * c2.imag) / denominator);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(2, 5);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    Complex c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;

    Complex c4 = c1 - c2;
    cout << "c1 - c2: " << c4 << endl;

    Complex c5 = c1 * c2;
    cout << "c1 * c2: " << c5 << endl;

    Complex c6 = c1 / c2;
    cout << "c1 / c2: " << c6 << endl;

    return 0;
}