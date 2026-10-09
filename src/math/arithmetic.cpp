#include "axiomforge/math/arithmetic.hpp"
namespace axf {
Integer add(Integer a,Integer b){return a+b;}
Integer subtract(Integer a,Integer b){return a-b;}
Integer multiply(Integer a,Integer b){return a*b;}
std::string classify(Integer n){if(n==0)return "zero";std::string s=n<0?"negative integer":"positive integer";s+=(n%2==0)?", even":", odd";return s;}
}
