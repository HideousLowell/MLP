#pragma once

#include <cmath>
#include <iostream>
#include <vector>

namespace s21 {

class S21Matrix {
    friend S21Matrix operator*(const double value, const S21Matrix& other);
    friend S21Matrix operator*(const S21Matrix& other, const double value);

 private:
    int _rows, _cols;
    double** _matrix;

 private:
    bool eq_matrix_loop(const S21Matrix& other);
    S21Matrix calculate_minor(int rows, int cols);
    void init_matrix();
    void delate_matrix();
    double determinant();

 public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    int getRows() const;
    int getCols() const;
    void setRows(int number);
    void setCols(int number);

    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    bool operator==(const S21Matrix& other);
    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double value);
    double& operator()(int row, int col);

    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    S21Matrix inverse_matrix();

    void transform_vector_to_matrix(const std::vector<double>& other);
    S21Matrix mul_vector(const S21Matrix& other);
    void input_value_in_zero_vector(int value);

    friend std::ostream& operator<<(std::ostream& out, const S21Matrix& other);
};

}  // namespace s21
