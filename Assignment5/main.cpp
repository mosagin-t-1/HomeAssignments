/*
 * Timofey Mosyagin
 * st142155@student.spbu.ru
 * My home assignment 5
 */
#include <iostream>
#include "Matrix.h"
#include "Rational.h"

int main() {
    std::cout << "Demo Assignment5: Matrix operations\n\n";

    Matrix<2,3,int> A({1,2,3,4,5,6});
    Matrix<3,2,int> B({7,8,9,10,11,12});
    auto C = A * B;
    std::cout << "A*B (2x2):\n" << C.toString() << "\n\n";

    Matrix<2,2,double> D({1.5, 2.5, 3.5, 4.5});
    D *= 2.0;
    std::cout << "2*D:\n" << D.toString() << "\n\n";
    std::cout << "D^T:\n" << D.transpose().toString() << "\n\n";

    Matrix<2,2,Rational> R({Rational(1,2), Rational(1,3), Rational(2,3), Rational(3,4)});
    std::cout << "R (2x2):\n" << R.toString() << "\n\n";
    std::cout << "R^T:\n" << R.transpose().toString() << "\n";

    return 0;
}

