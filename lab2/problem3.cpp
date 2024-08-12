/*To write a C++ program to manipulate complex numbers using operator 
overloading. (addition,subtraction,multiplication,division)*/
// #include <iostream>
// using namespace std;

// class Complex {
// private:
//     float real;
//     float imag;

// public:
//     Complex() : real(0), imag(0) {}
//     Complex(float rl, float img) : real(rl), imag(img) {}

//     void display() 
//     {
//         cout << "(" << real << "," << imag << ")";
//     }

//     friend Complex operator+(Complex c1, Complex c2);
//     friend Complex operator-(Complex c1, Complex c2);
//     friend Complex operator*(Complex c1, Complex c2);
//     friend Complex operator/(Complex c1, Complex c2);
// };

// Complex operator+(Complex c1, Complex c2) {
//     Complex temp;
//     temp.real = c1.real + c2.real;
//     temp.imag = c1.imag + c2.imag;
//     return temp;
// }

// Complex operator-(Complex c1, Complex c2) {
//     Complex temp;
//     temp.real = c1.real - c2.real;
//     temp.imag = c1.imag - c2.imag;
//     return temp;
// }

// Complex operator*(Complex c1, Complex c2) {
//     Complex temp;
//     temp.real = c1.real * c2.real - c1.imag * c2.imag;
//     temp.imag = c1.real * c2.imag + c1.imag * c2.real;
//     return temp;
// }

// Complex operator/(Complex c1, Complex c2) {
//     Complex temp;
//     float denominator = c2.real * c2.real + c2.imag * c2.imag;
//     if (denominator != 0) {
//         temp.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
//         temp.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
//     } else {
//         cout << "Division by zero error!";
//         temp.real = temp.imag = 0;
//     }
//     return temp;
// }

// int main() {
//     Complex c1(3, 4), c2(1, 2);

//     Complex c3 = c1 + c2;
//     Complex c4 = c1 - c2;
//     Complex c5 = c1 * c2;
//     Complex c6 = c1 / c2;

//     cout << "c1: ";
//     c1.display();
//     cout << endl;

//     cout << "c2: ";
//     c2.display();
//     cout << endl;

//     cout << "c1 + c2: ";
//     c3.display();
//     cout << endl;

//     cout << "c1 - c2: ";
//     c4.display();
//     cout << endl;

//     cout << "c1 * c2: ";
//     c5.display();
//     cout << endl;

//     cout << "c1 / c2: ";
//     c6.display();
//     cout << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() {
    real=0;
    imag=0;
    }
    Complex(float rl, float img) : real(rl), imag(img) {}

    void display() const
    {
        cout << "(" << real << "," << imag << ")";
    }

    void input()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    friend Complex operator+(Complex c1, Complex c2);
    friend Complex operator-(Complex c1, Complex c2);
    friend Complex operator*(Complex c1, Complex c2);
    friend Complex operator/(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

Complex operator-(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

Complex operator*(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real * c2.real - c1.imag * c2.imag;
    temp.imag = c1.real * c2.imag + c1.imag * c2.real;
    return temp;
}

Complex operator/(Complex c1, Complex c2) {
    Complex temp;
    float denominator = c2.real * c2.real + c2.imag * c2.imag;
    if (denominator != 0) {
        temp.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
        temp.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    } else {
        cout << "Division by zero error!";
        temp.real = temp.imag = 0;
    }
    return temp;
}

int main() {
    Complex c1, c2;

    cout << "Enter the first complex number:" << endl;
    c1.input();

    cout << "Enter the second complex number:" << endl;
    c2.input();

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "c1: ";
    c1.display();
    cout << endl;

    cout << "c2: ";
    c2.display();
    cout << endl;

    cout << "c1 + c2: ";
    c3.display();
    cout << endl;

    cout << "c1 - c2: ";
    c4.display();
    cout << endl;

    cout << "c1 * c2: ";
    c5.display();
    cout << endl;

    cout << "c1 / c2: ";
    c6.display();
    cout << endl;

    return 0;
}

