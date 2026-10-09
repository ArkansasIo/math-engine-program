#include "axiomforge/math/polynomial.hpp"
#include <cmath>
#include <sstream>
namespace axf::math {
Polynomial::Polynomial(std::vector<double> c):coefficients_(std::move(c)){normalize();}
void Polynomial::normalize(){while(coefficients_.size()>1&&std::abs(coefficients_.back())<1e-14)coefficients_.pop_back();if(coefficients_.empty())coefficients_.push_back(0.0);}
Polynomial Polynomial::variable(){return Polynomial({0.0,1.0});}
std::size_t Polynomial::degree()const noexcept{return coefficients_.size()-1;}
double Polynomial::coefficient(std::size_t p)const noexcept{return p<coefficients_.size()?coefficients_[p]:0.0;}
double Polynomial::evaluate(double x)const noexcept{double y=0;for(auto i=coefficients_.rbegin();i!=coefficients_.rend();++i)y=y*x+*i;return y;}
Polynomial Polynomial::derivative()const{if(degree()==0)return Polynomial();std::vector<double>r(degree());for(std::size_t i=1;i<coefficients_.size();++i)r[i-1]=coefficients_[i]*static_cast<double>(i);return Polynomial(std::move(r));}
Polynomial Polynomial::integral(double c)const{std::vector<double>r(coefficients_.size()+1);r[0]=c;for(std::size_t i=0;i<coefficients_.size();++i)r[i+1]=coefficients_[i]/static_cast<double>(i+1);return Polynomial(std::move(r));}
std::string Polynomial::to_string(const std::string& v)const{std::ostringstream o;bool first=true;for(std::size_t i=coefficients_.size();i-->0;){double c=coefficients_[i];if(std::abs(c)<1e-14)continue;if(!first)o<<(c<0?" - ":" + ");else if(c<0)o<<"-";double a=std::abs(c);if(i==0||a!=1.0)o<<a;if(i>0){o<<v;if(i>1)o<<"^"<<i;}first=false;}return first?"0":o.str();}
Polynomial operator+(const Polynomial&a,const Polynomial&b){std::vector<double>r(std::max(a.coefficients_.size(),b.coefficients_.size()));for(std::size_t i=0;i<r.size();++i)r[i]=a.coefficient(i)+b.coefficient(i);return Polynomial(std::move(r));}
Polynomial operator-(const Polynomial&a,const Polynomial&b){std::vector<double>r(std::max(a.coefficients_.size(),b.coefficients_.size()));for(std::size_t i=0;i<r.size();++i)r[i]=a.coefficient(i)-b.coefficient(i);return Polynomial(std::move(r));}
Polynomial operator*(const Polynomial&a,const Polynomial&b){std::vector<double>r(a.degree()+b.degree()+1,0.0);for(std::size_t i=0;i<a.coefficients_.size();++i)for(std::size_t j=0;j<b.coefficients_.size();++j)r[i+j]+=a.coefficients_[i]*b.coefficients_[j];return Polynomial(std::move(r));}
}
