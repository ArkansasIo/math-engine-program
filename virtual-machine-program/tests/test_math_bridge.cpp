#include "math/MathBridge.hpp"
#include <cassert>
#include <string_view>
int main(){
 using mathbridge::Operation;
 assert(mathbridge::name(Operation::Add1024)=="MATH-1024-ADD");
 assert(mathbridge::name(Operation::NormalizeState)=="QMATH-NORMALIZE");
 assert(mathbridge::name(Operation::MeasurementProbability)=="QMATH-MEASURE-PROB");
 return 0;
}