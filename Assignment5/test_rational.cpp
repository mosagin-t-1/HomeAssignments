#include "Rational.h"
#include <gtest/gtest.h>

TEST(RationalTest, Normalize) {
    Rational r(2, 4);
    EXPECT_EQ(r.num(), 1);
    EXPECT_EQ(r.den(), 2);

    Rational r2(-6, -8);
    EXPECT_EQ(r2.num(), 3);
    EXPECT_EQ(r2.den(), 4);

    Rational r0(0, 5);
    EXPECT_EQ(r0.num(), 0);
    EXPECT_EQ(r0.den(), 1);
}

TEST(RationalTest, Arithmetic) {
    Rational a(1,2), b(1,3);
    EXPECT_EQ(a + b, Rational(5,6));
    EXPECT_EQ(a - b, Rational(1,6));
    EXPECT_EQ(a * b, Rational(1,6));
    EXPECT_EQ(a / b, Rational(3,2));
}

TEST(RationalExceptions, ZeroDenominator) {
    EXPECT_THROW(Rational(1,0), std::invalid_argument);
}

TEST(RationalExceptions, DivisionByZero) {
    Rational a(1,2);
    Rational z(0,1);
    EXPECT_THROW(a / z, std::domain_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

