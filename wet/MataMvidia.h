#include "Matrix.h"
#include <string.h>

class MataMvidia {
private:
    int numFrames;
    Matrix *frames;
    std::string nameCreator;        //שם יוצר
    std::string nameMovie;         //  שם סרט
public:
    MataMvidia(const std::string& nameMovie,
               const std::string& nameCreator,
               Matrix frames[],
               int numFrames);


    MataMvidia(const MataMvidia& m);
    ~MataMvidia();
    MataMvidia& operator= (const MataMvidia& matrix);
    MataMvidia& operator+=(const MataMvidia& other);
    MataMvidia& operator+=(const Matrix& other);
    MataMvidia operator+(const MataMvidia& other) const;
    const Matrix& operator[](int index)const;
    Matrix& operator[](int index);
    friend  std::ostream& operator<<(std::ostream &os,const MataMvidia& m) ;

};

