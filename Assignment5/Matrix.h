#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <sstream>
#include <cstddef>
#include <string>

template <std::size_t M, std::size_t N, typename T>
class Matrix {
public:
    Matrix();
    Matrix(const std::initializer_list<T>& values);

    T& operator()(std::size_t i, std::size_t j);
    const T& operator()(std::size_t i, std::size_t j) const;

    std::size_t rows() const { return M; }
    std::size_t cols() const { return N; }

    Matrix<M, N, T> operator+(const Matrix<M, N, T>& other) const;
    Matrix<M, N, T>& operator+=(const Matrix<M, N, T>& other);

    Matrix<M, N, T> operator*(const T& scalar) const;
    Matrix<M, N, T>& operator*=(const T& scalar);

    template <std::size_t P>
    Matrix<M, P, T> operator*(const Matrix<N, P, T>& other) const;

    Matrix<N, M, T> transpose() const;

    bool operator==(const Matrix<M, N, T>& other) const;
    bool operator!=(const Matrix<M, N, T>& other) const;

    std::string toString() const;

private:
    std::vector<T> data_;
};


template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T>::Matrix() : data_(M * N) {}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T>::Matrix(const std::initializer_list<T>& values) : data_(M * N) {
    if (values.size() != M * N) {
        std::ostringstream os;
        os << "Initializer list size must be " << (M * N);
        throw std::invalid_argument(os.str());
    }
    std::size_t idx = 0;
    for (const auto& v : values) data_[idx++] = v;
}

template <std::size_t M, std::size_t N, typename T>
T& Matrix<M, N, T>::operator()(std::size_t i, std::size_t j) {
    if (i >= M || j >= N) throw std::out_of_range("Matrix index out of range");
    return data_[i * N + j];
}

template <std::size_t M, std::size_t N, typename T>
const T& Matrix<M, N, T>::operator()(std::size_t i, std::size_t j) const {
    if (i >= M || j >= N) throw std::out_of_range("Matrix index out of range");
    return data_[i * N + j];
}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T> Matrix<M, N, T>::operator+(const Matrix<M, N, T>& other) const {
    Matrix<M, N, T> res;
    for (std::size_t i = 0; i < M * N; ++i) res.data_[i] = data_[i] + other.data_[i];
    return res;
}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T>& Matrix<M, N, T>::operator+=(const Matrix<M, N, T>& other) {
    for (std::size_t i = 0; i < M * N; ++i) data_[i] += other.data_[i];
    return *this;
}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T> Matrix<M, N, T>::operator*(const T& scalar) const {
    Matrix<M, N, T> res;
    for (std::size_t i = 0; i < M * N; ++i) res.data_[i] = data_[i] * scalar;
    return res;
}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T>& Matrix<M, N, T>::operator*=(const T& scalar) {
    for (std::size_t i = 0; i < M * N; ++i) data_[i] *= scalar;
    return *this;
}

template <std::size_t M, std::size_t N, typename T>
template <std::size_t P>
Matrix<M, P, T> Matrix<M, N, T>::operator*(const Matrix<N, P, T>& other) const {
    Matrix<M, P, T> res;
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t j = 0; j < P; ++j) {
            T sum = T();
            for (std::size_t k = 0; k < N; ++k) {
                sum = sum + ((*this)(i, k) * other(k, j));
            }
            res(i, j) = sum;
        }
    }
    return res;
}

template <std::size_t M, std::size_t N, typename T>
Matrix<N, M, T> Matrix<M, N, T>::transpose() const {
    Matrix<N, M, T> res;
    for (std::size_t i = 0; i < M; ++i)
        for (std::size_t j = 0; j < N; ++j)
            res(j, i) = (*this)(i, j);
    return res;
}

template <std::size_t M, std::size_t N, typename T>
bool Matrix<M, N, T>::operator==(const Matrix<M, N, T>& other) const {
    for (std::size_t i = 0; i < M * N; ++i)
        if (!(data_[i] == other.data_[i])) return false;
    return true;
}

template <std::size_t M, std::size_t N, typename T>
bool Matrix<M, N, T>::operator!=(const Matrix<M, N, T>& other) const {
    return !(*this == other);
}

template <std::size_t M, std::size_t N, typename T>
std::string Matrix<M, N, T>::toString() const {
    std::ostringstream os;
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            os << (*this)(i, j);
            if (j + 1 < N) os << ' ';
        }
        if (i + 1 < M) os << '\n';
    }
    return os.str();
}

template <std::size_t M, std::size_t N, typename T>
Matrix<M, N, T> operator*(const T& scalar, const Matrix<M, N, T>& mat) {
    return mat * scalar;
}

#endif

