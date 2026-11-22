#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
private:
    int num, den;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a == 0) ? 1 : a;
    }

    void simplify() {
        if (den == 0) den = 1;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = gcd(num, den);
        num /= common;
        den /= common;
    }

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }

    bool operator==(const Fraction& other) const {
        return (num == other.num && den == other.den);
    }

    bool operator<(const Fraction& other) const {
        return (num * other.den < other.num * den);
    }

    Fraction& operator++() {
        num = num + den;
        simplify();
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    in >> f.num >> f.den;
    f.simplify();
    return in;
}

int main() {
    Fraction a(1, 2), b(3, 4);

    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    if (Fraction(2, 4) == a) {
        cout << "2/4 is equal to " << a << endl;
    }
    if (a < b) {
        cout << a << " is less than " << b << endl;
    }

    ++a;
    cout << "After ++a: " << a << endl;

    Fraction userFrac;
    cout << "Enter numerator and denominator: ";
    cin >> userFrac;
    cout << "You entered " << userFrac << endl;

    return 0;
}