#ifndef MATRIX_H
#define MATRIX_H



#include <string>
#include <iostream>
#include "Utilities.h"
#include <cmath>
class Matrix {
private:
    int rows;
    int columns;
    int *point; //points to the start of the matrix

public:
    Matrix(); //first constructor
    Matrix(int rows, int columns);// second construtor
    Matrix(int columns, int rows, int initValue);//third contructor
    Matrix(const Matrix& m); //copy constructor used
    ~Matrix();

    int &operator()(int row, int col); //for changing stuff
    int  operator()(int row, int col) const;

    //for reading only
    Matrix& operator=(const Matrix &other);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    Matrix operator+( const Matrix &matrix2) const;

    Matrix operator-(const Matrix &matrix2)const;

    Matrix operator*( const Matrix &matrix2)const;

    Matrix &operator+=(const Matrix &other);

    Matrix &operator-=(const Matrix &other);

    Matrix &operator*=(const Matrix &other);

    Matrix operator-() const;

    Matrix operator*(int scalar) const;

    Matrix &operator*=(int scalar);

    friend Matrix operator*(int scalar, const Matrix& matrix);

    bool operator==(const Matrix &other) const;

    bool operator!=(const Matrix &other) const;

    Matrix rotateClockwise() const;

    Matrix rotateCounterClockwise() const;

    Matrix transpose() const;

    double CalcFrobeniusNorm(const Matrix &matrix);

};

#endif // MATRIX_H
