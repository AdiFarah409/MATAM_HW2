#include "Matrix.h"

// all the constructors
Matrix::Matrix() : rows(0),columns(0),point(nullptr){}

Matrix::Matrix(int rows,int columns): rows(rows),columns(columns){

    point = new int[rows*columns];
}

Matrix::Matrix(int rows, int columns, int initValue) : rows(rows), columns(columns) {
    point = new int[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        point[i] = initValue;
    }
}

// destructor
Matrix::~Matrix() {
    delete[] point;
}

Matrix::Matrix(const Matrix& m) : rows(m.rows), columns(m.columns), point(nullptr) {
    point = new int[rows * columns];
    for (int i = 0; i < rows * columns; ++i)
        point[i] = m.point[i];
}

//the () operator 4.3.4
int& Matrix::operator()(int row, int col) //for changing stuff
{
    if (row < 0 || col < 0 || row >= rows || col >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return point[row * columns + col];
}

int Matrix::operator()(int row, int col) const //for reading only
{
    if (row < 0 || col < 0 || row >= rows || col >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return point[row * columns + col];
}


Matrix& Matrix::operator=(const Matrix &other){
    if (this == &other) {
        return *this;
    }

    delete[] point; //free the old matrix

    rows = other.rows;
    columns = other.columns;

    point = new int[rows * columns]; //new must be used because different matrices must not point to the same place

    for (int i = 0; i < rows * columns; ++i) {
        point[i] = other.point[i];
    }

    return (*this);
}


// the << operator 4.3.5

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    if (matrix.rows == 0 || matrix.columns == 0) {
        return os;
    }
    for (int i = 0; i < matrix.rows; i++) {
        os << "|";
        for (int j = 0; j < matrix.columns; j++) {
            os << matrix(i, j) << "|";
        }
        os << std::endl;
    }
    return os;
}

// 4.3.6

//the + operator
Matrix Matrix::operator+(const Matrix& matrix) const{
    if (rows != matrix.rows || columns != matrix.columns) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix result(rows , columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result(i, j)= (*this)(i, j) + matrix(i, j);
        }
    }
    return result;
}


// the - operator
Matrix Matrix::operator-(const Matrix& matrix) const {
    if (rows != matrix.rows || columns != matrix.columns) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix result(rows, columns);
    result =(*this)+(-matrix); //using the unary minus
    return result;
}


// the * operator

Matrix Matrix:: operator*(const Matrix& matrix) const {
    if (columns != matrix.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }

    Matrix result(rows, matrix.columns);
    for (int i = 0; i < (*this).rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            int sum = 0;
            for (int k = 0; k < (*this).columns; ++k) {
                sum += (*this)(i, k) * matrix(k, j);
            }
            result(i,j)= sum;
        }
    }
    return result;
}

// +=

Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

// -=
Matrix& Matrix::operator-=(const Matrix& other) {
    (*this) = (*this) - other;
    return *this;
}

//*=
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// -()
Matrix Matrix::operator-() const {
    Matrix result(rows, columns);
    result= (*this)*-(1);
    return result;
}

// *scalar multiplication

Matrix Matrix:: operator*(int scalar) const {
    Matrix result(*this);

    for (int i=0;i< columns*rows ;i++)
    {
        result.point[i]*=scalar;
    }

    return result;
}

//*= scalar

Matrix& Matrix::operator*=(int scalar)  {
    (*this) = (*this) * scalar;
    return *this;
}

// the == operator
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || columns != other.columns) {
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if ((*this)(i, j) != other(i, j)) {
                return false;
            }
        }
    }
    return true;
}



Matrix operator*(int scalar, const Matrix& matrix) {
    return matrix * scalar;  // reuse member operator*(int) const
}


// the != operator



bool Matrix::operator!=(const Matrix& other) const {
    return !((*this) == other);  // new matrix with appropriate dimensions
}

// rotaation 4.3.8

Matrix Matrix::rotateClockwise() const {
    Matrix rotated(columns, rows);
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            rotated(i, j) = (*this)(rows - 1 - j, i);
        }
    }
    return rotated;
}



// in order to spin counter-clockwise we need to rotate it clockwise 3 times
Matrix Matrix::rotateCounterClockwise() const {
    Matrix once  = rotateClockwise();
    once = once.rotateClockwise();
    once = once.rotateClockwise();
    return once;
}


// transpose

Matrix Matrix::transpose() const{
    Matrix transposed(columns, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposed(j, i)= (*this)(i, j);
        }
    }

    return transposed;
}

//norm calc
double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    double sum = 0.0;
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            double v = matrix(i, j);
            sum += v * v;
        }
    }
    return std::sqrt(sum);
}



double Matrix::CalcDeterminant(const Matrix& matrix) {

    if (matrix.rows == 0 || matrix.columns == 0) {
        return 0;
    }

    if (matrix.rows != matrix.columns) {
        exitWithError(MatamErrorType::NotSquareMatrix);
    }

    if (matrix.rows == 1) {
        return matrix(0, 0);
    }

    if (matrix.rows == 2) {
        return matrix(0,0) * matrix(1,1) - matrix(0,1) * matrix(1,0);
    }

    double det = 0.0;
    for (int j = 0; j < matrix.columns; ++j) {
        Matrix minor(matrix.rows - 1, matrix.columns - 1);

        for (int i = 1; i < matrix.rows; ++i) {
            int colIndex = 0;
            for (int k = 0; k < matrix.columns; ++k) {
                if (k == j) continue;
                minor(i - 1, colIndex) = matrix(i, k);
                ++colIndex;
            }
        }

        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        det += sign * matrix(0, j) * Matrix::CalcDeterminant(minor);
    }

    return det;
}





