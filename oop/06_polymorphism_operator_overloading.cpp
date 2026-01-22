
#include <iostream>

class Complex{
public:

    int real;
    int imag;

    Complex(int r, int i):
    real(r), imag(i) {}

    Complex operator+(const Complex& obj){
        return Complex(real + obj.real, imag + obj.imag);
    }
};

int main() {


    Complex c1(10, 50);
    Complex c2(20, 40);

    Complex c3 = c1 +c2;
    std::cout << "Result: " << c3.real << " + i" << c3.imag << std::endl;
}