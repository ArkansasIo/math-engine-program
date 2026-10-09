#include "math/MathBridge.hpp"
#include <cassert>
int main(){using mathbridge::MathBridge;assert(MathBridge::name(MathBridge::Operation::Add1024)=="MATH-1024-ADD");assert(MathBridge::name(MathBridge::Operation::NormalizeState)=="QMATH-NORMALIZE");return 0;}