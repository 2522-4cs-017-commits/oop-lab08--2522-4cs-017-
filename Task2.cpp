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

    void print() const {
        cout << num << "/" << den;
    }
};

int main() {
    Fraction a(1, 2), b(3, 4);
    if (Fraction(2, 4) == a) cout << "2/4 is equal to 1/2" << endl;
    if (a < b) cout << "1/2 is less than 3/4" << endl;
    return 0;
}