#include "MataMvidia.h"

MataMvidia::~MataMvidia() {
    delete[] frames;
}

MataMvidia::MataMvidia(const std::string& nameMovie,
                       const std::string& nameCreator,
                       Matrix framesArr[],
                       int numFrames)
        : numFrames(numFrames),
          frames(nullptr),
          nameCreator(nameCreator),
          nameMovie(nameMovie)
{
    this->frames = new Matrix[numFrames];
    for (int i = 0; i < numFrames; ++i) {
        this->frames[i] = framesArr[i];
    }
}



MataMvidia::MataMvidia(const MataMvidia& matrix) {
    frames = new Matrix[matrix.numFrames];
    this->nameMovie = matrix.nameMovie;
    this->nameCreator = matrix.nameCreator;
    this->numFrames = matrix.numFrames;
    for(int i=0;i<matrix.numFrames;i++) {
        frames[i]=matrix.frames[i];
    }
}

MataMvidia& MataMvidia::operator=(const MataMvidia& matrix) {
    if(this==&matrix) {
        return *this;
    }
    delete [] frames;
    this->nameMovie = matrix.nameMovie;
    this->nameCreator = matrix.nameCreator;
    this->numFrames = matrix.numFrames;
    this->frames = new Matrix[matrix.numFrames];
    for(int i=0 ; i < matrix.numFrames ; i++) {
            frames[i]=matrix.frames[i];
        }

    return *this;
}


MataMvidia& MataMvidia::operator+=(const Matrix& other) {
    Matrix *matrix = new Matrix[numFrames+1];
    for(int i=0;i<numFrames;i++) {
        matrix[i]=frames[i];
    } // fill in order and then add the new one
    matrix[numFrames] = other;
    delete [] frames;
    frames = matrix;
    numFrames += 1;
    return *this;
}


//using the first implementation of the += operator
MataMvidia& MataMvidia::operator+=(const MataMvidia& other)
{
 for (int i=0;i<other.numFrames;i++)
  {
     *this += other[i];
  }
    return *this;
}

// uses the += operator
MataMvidia MataMvidia::operator+(const MataMvidia& other) const{
    MataMvidia result = *this;
    result+=other;
    return result;
}

//for reading const verison
const Matrix& MataMvidia::operator[](int index)const {
    if(index>(numFrames-1) || index<0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[index];
}

//for changing
Matrix& MataMvidia::operator[](int index){
    if(index>(numFrames-1) || index<0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[index];
}

// print according to said order.
std::ostream &operator<<(std::ostream &os,const MataMvidia& matrix) {
    os << "Movie Name: " << matrix.nameMovie << std::endl;
    os << "Author: " << matrix.nameCreator << std::endl << std::endl;

    for(int i=0;i<matrix.numFrames;i++) {
        os << "Frame " << i << ":" <<std::endl;
        os << matrix.frames[i] << std::endl;

    }
    os << "-----End of Movie-----" << std::endl;
    return os;
}