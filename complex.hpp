#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    std::string toString() const {
        std::ostringstream os;
        os << "(" << real << ", " << imag << ")";
        return os.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator>(const Complex& other) const {
        return (real * real + imag * imag) > (other.real * real + other.imag * other.imag);
    }

    bool operator<(const Complex& other) const {
        return (real * real + imag * imag) < (other.real * real + other.imag * other.imag);
    }
};

#endif // COMPLEX_HPP
