#pragma once
#include <string_view>
namespace mathbridge {
constexpr std::string_view version="AxiomForge Math Bridge v1";
enum class Operation { Add1024, VectorAdd1024, NormalizeState, MeasurementProbability };
std::string_view name(Operation);
}
