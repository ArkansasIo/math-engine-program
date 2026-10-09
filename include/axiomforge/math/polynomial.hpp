#pragma once
#include <cstddef>
#include <string>
#include <vector>
namespace axf::math {
class Polynomial {
public:
 explicit Polynomial(std::vector<double> coefficients={0.0});
 static Polynomial variable();
 std::size_t degree() const noexcept;
 double coefficient(std::size_t power) const noexcept;
 double evaluate(double x) const noexcept;
 Polynomial derivative() const;
 Polynomial integral(double constant=0.0) const;
 std::string to_string(const std::string& variable="x") const;
 friend Polynomial operator+(const Polynomial&,const Polynomial&);
 friend Polynomial operator-(const Polynomial&,const Polynomial&);
 friend Polynomial operator*(const Polynomial&,const Polynomial&);
private:
 std::vector<double> coefficients_;
 void normalize();
};
}
