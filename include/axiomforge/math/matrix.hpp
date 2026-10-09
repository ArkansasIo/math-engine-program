#pragma once
#include <cstddef>
#include <vector>
namespace axf::math {
class Matrix {
public:
 Matrix(std::size_t rows,std::size_t cols,double initial=0.0);
 Matrix(std::vector<std::vector<double>> values);
 std::size_t rows()const noexcept{return rows_;}
 std::size_t cols()const noexcept{return cols_;}
 double& at(std::size_t row,std::size_t col);
 double at(std::size_t row,std::size_t col)const;
 Matrix transpose()const;
 double determinant()const;
 friend Matrix operator+(const Matrix&,const Matrix&);
 friend Matrix operator*(const Matrix&,const Matrix&);
private:
 std::size_t rows_,cols_;
 std::vector<double> data_;
};
}
