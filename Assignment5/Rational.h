#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdint>
#include <iostream>

class Rational {
public:
    Rational();
    Rational(int64_t num, int64_t den);

    int64_t num() const;
    int64_t den() const;

    void normalize();

    Rational operator+(const Rational& r) const;
    Rational operator-(const Rational& r) const;
    Rational operator*(const Rational& r) const;
    Rational operator/(const Rational& r) const;

    Rational& operator+=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator*=(const Rational& r);
    Rational& operator/=(const Rational& r);

    bool operator==(const Rational& r) const;
    bool operator!=(const Rational& r) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

private:
    int64_t p; // numerator
    int64_t q; // denominator

    static int64_t gcd_int64(int64_t a, int64_t b);
};

#endif

