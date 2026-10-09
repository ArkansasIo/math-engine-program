#pragma once
namespace axf::math {
enum class Unit { Meter, Kilometer, Centimeter, Foot, Mile, Second, Minute, Hour, Gram, Kilogram, Celsius, Fahrenheit, Kelvin };
double convert_unit(double value,Unit from,Unit to);
}
