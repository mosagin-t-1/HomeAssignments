#include "Matrix.h"
#include "Rational.h"
#include <gtest/gtest.h>

TEST(MatrixIntTest, AddAndScalar) {
    Matrix<2,2,int> A({1,2,3,4});
    Matrix<2,2,int> B({4,3,2,1});
    auto C = A + B;
    Matrix<2,2,int> expected({5,5,5,5});
    EXPECT_EQ(C, expected);
    C *= 2;
    Matrix<2,2,int> expected2({10,10,10,10});
    EXPECT_EQ(C, expected2);
}

TEST(MatrixIntTest, Multiply) {
    Matrix<2,3,int> A({1,2,3,4,5,6});
    Matrix<3,2,int> B({7,8,9,10,11,12});
    auto C = A * B; // 2x2
    Matrix<2,2,int> expected({58,64,139,154});
    EXPECT_EQ(C, expected);
}

TEST(MatrixDoubleTest, MultiplyAndNear) {
    Matrix<2,2,double> A({1.1,2.2,3.3,4.4});
    Matrix<2,2,double> B({5.5,6.6,7.7,8.8});
    auto C = A * B;
    double expect00 = 1.1*5.5 + 2.2*7.7;
    EXPECT_NEAR(C(0,0), expect00, 1e-9);
}

TEST(MatrixRationalTest, Operations) {
    Matrix<2,2,Rational> A({Rational(1,2), Rational(1,3), Rational(1,4), Rational(1,5)});
    Matrix<2,2,Rational> B({Rational(1,6), Rational(1,7), Rational(1,8), Rational(1,9)});
    auto C = A + B;
    EXPECT_EQ(C(0,0), Rational(2,3)); // 1/2 + 1/6 = 2/3
    auto D = A * Rational(2,1);
    EXPECT_EQ(D(1,0), Rational(1,2)); // 1/4 * 2 = 1/2
    auto At = A.transpose();
    EXPECT_EQ(At(0,1), Rational(1,4));
}

TEST(MatrixErrors, BadInitializerSize) {
    EXPECT_THROW((Matrix<2,2,int>({1,2,3})), std::invalid_argument);
}

TEST(MatrixErrors, IndexOutOfRange) {
    Matrix<2,2,int> A({1,2,3,4});
    EXPECT_THROW(A(2,1), std::out_of_range);
}

TEST(MatrixCopy, CopyIndependence) {
    Matrix<2,2,int> A({1,2,3,4});
    Matrix<2,2,int> B = A;
    B(0,0) = 99;
    EXPECT_EQ(A(0,0), 1);
    EXPECT_EQ(B(0,0), 99);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

