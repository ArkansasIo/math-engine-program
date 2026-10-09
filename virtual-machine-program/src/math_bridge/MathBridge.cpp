#include "math/MathBridge.hpp"
namespace mathbridge {
std::string_view name(Operation o){switch(o){case Operation::Add1024:return "MATH-1024-ADD";case Operation::VectorAdd1024:return "V1024-ADD";case Operation::NormalizeState:return "QMATH-NORMALIZE";case Operation::MeasurementProbability:return "QMATH-MEASURE-PROB";}return "UNKNOWN";}
}
