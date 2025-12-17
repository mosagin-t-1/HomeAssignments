/*
 * Timofey Mosyagin
 * st142155@student.spbu.ru
 * My home assignment 5
 */
#include "Rational.h"
#include <stdexcept>

int64_t Rational::gcd_int64(int64_t a, int64_t b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0 && b == 0) return 1;
    while (b != 0) {
        int64_t t = a % b;
        a = b;
        b = t;
    }
    return a == 0 ? 1 : a;
}

Rational::Rational() : p(0), q(1) {}

Rational::Rational(int64_t num, int64_t den) : p(num), q(den) {
    if (q == 0) throw std::invalid_argument("Denominator cannot be zero");
    normalize();
}

int64_t Rational::num() const { return p; }
int64_t Rational::den() const { return q; }

void Rational::normalize() {
    if (q < 0) { p = -p; q = -q; }
    if (p == 0) { q = 1; return; }
    int64_t g = gcd_int64(p, q);
    p /= g;
    q /= g;
}

Rational Rational::operator+(const Rational& r) const {
    return Rational(p * r.q + r.p * q, q * r.q);
}

Rational Rational::operator-(const Rational& r) const {
    return Rational(p * r.q - r.p * q, q * r.q);
}

Rational Rational::operator*(const Rational& r) const {
    return Rational(p * r.p, q * r.q);
}

Rational Rational::operator/(const Rational& r) const {
    if (r.p == 0) throw std::domain_error("Division by zero");
    return Rational(p * r.q, q * r.p);
}

Rational& Rational::operator+=(const Rational& r) { *this = *this + r; return *this; }
Rational& Rational::operator-=(const Rational& r) { *this = *this - r; return *this; }
Rational& Rational::operator*=(const Rational& r) { *this = *this * r; return *this; }
Rational& Rational::operator/=(const Rational& r) { *this = *this / r; return *this; }

bool Rational::operator==(const Rational& r) const { return p == r.p && q == r.q; }
bool Rational::operator!=(const Rational& r) const { return !(*this == r); }

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.p << '/' << r.q;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int64_t n = 0, d = 1;
    if (!(is >> n)) return is;
    if (is.peek() == '/') {
        char sep;
        is >> sep >> d;
        r = Rational(n, d);
    } else {
        r = Rational(n, 1);
    }
    return is;
}

