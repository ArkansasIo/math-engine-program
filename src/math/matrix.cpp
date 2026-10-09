#include "axiomforge/math/matrix.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
namespace axf::math {
Matrix::Matrix(std::size_t r,std::size_t c,double v):rows_(r),cols_(c),data_(r*c,v){if(r==0||c==0)throw std::invalid_argument("matrix dimensions must be positive");}
Matrix::Matrix(std::vector<std::vector<double>> v):rows_(v.size()),cols_(v.empty()?0:v.front().size()),data_(){if(rows_==0||cols_==0)throw std::invalid_argument("matrix must not be empty");for(const auto&row:v){if(row.size()!=cols_)throw std::invalid_argument("matrix rows must have equal length");data_.insert(data_.end(),row.begin(),row.end());}}
double& Matrix::at(std::size_t r,std::size_t c){if(r>=rows_||c>=cols_)throw std::out_of_range("matrix index");return data_[r*cols_+c];}
double Matrix::at(std::size_t r,std::size_t c)const{if(r>=rows_||c>=cols_)throw std::out_of_range("matrix index");return data_[r*cols_+c];}
Matrix Matrix::transpose()const{Matrix out(cols_,rows_);for(std::size_t r=0;r<rows_;++r)for(std::size_t c=0;c<cols_;++c)out.at(c,r)=at(r,c);return out;}
double Matrix::determinant()const{if(rows_!=cols_)throw std::invalid_argument("determinant requires square matrix");Matrix m=*this;double det=1;for(std::size_t c=0;c<cols_;++c){std::size_t pivot=c;for(std::size_t r=c+1;r<rows_;++r)if(std::abs(m.at(r,c))>std::abs(m.at(pivot,c)))pivot=r;if(std::abs(m.at(pivot,c))<1e-12)return 0;if(pivot!=c){for(std::size_t j=0;j<cols_;++j)std::swap(m.at(pivot,j),m.at(c,j));det=-det;}double p=m.at(c,c);det*=p;for(std::size_t r=c+1;r<rows_;++r){double f=m.at(r,c)/p;for(std::size_t j=c+1;j<cols_;++j)m.at(r,j)-=f*m.at(c,j);}}return det;}
Matrix operator+(const Matrix&a,const Matrix&b){if(a.rows_!=b.rows_||a.cols_!=b.cols_)throw std::invalid_argument("matrix dimensions must match");Matrix r(a.rows_,a.cols_);for(std::size_t i=0;i<r.data_.size();++i)r.data_[i]=a.data_[i]+b.data_[i];return r;}
Matrix operator*(const Matrix&a,const Matrix&b){if(a.cols_!=b.rows_)throw std::invalid_argument("matrix dimensions are incompatible");Matrix r(a.rows_,b.cols_);for(std::size_t i=0;i<a.rows_;++i)for(std::size_t k=0;k<a.cols_;++k)for(std::size_t j=0;j<b.cols_;++j)r.at(i,j)+=a.at(i,k)*b.at(k,j);return r;}
}
