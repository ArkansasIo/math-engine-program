#include "axiomforge/math/units.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
namespace {enum class Dimension{Length,Time,Mass,Temperature};struct UnitInfo{Dimension dimension;double scale;double offset;};
UnitInfo info(Unit u){switch(u){case Unit::Meter:return{Dimension::Length,1,0};case Unit::Kilometer:return{Dimension::Length,1000,0};case Unit::Centimeter:return{Dimension::Length,.01,0};case Unit::Foot:return{Dimension::Length,.3048,0};case Unit::Mile:return{Dimension::Length,1609.344,0};case Unit::Second:return{Dimension::Time,1,0};case Unit::Minute:return{Dimension::Time,60,0};case Unit::Hour:return{Dimension::Time,3600,0};case Unit::Gram:return{Dimension::Mass,.001,0};case Unit::Kilogram:return{Dimension::Mass,1,0};case Unit::Celsius:return{Dimension::Temperature,1,273.15};case Unit::Fahrenheit:return{Dimension::Temperature,5.0/9.0,273.15-32.0*5.0/9.0};case Unit::Kelvin:return{Dimension::Temperature,1,0};}throw std::invalid_argument("unknown unit");}}
double convert_unit(double value,Unit from,Unit to){if(!std::isfinite(value))throw std::invalid_argument("unit conversion requires a finite value");auto a=info(from),b=info(to);if(a.dimension!=b.dimension)throw std::invalid_argument("units belong to different dimensions");double base=value*a.scale+a.offset;return(base-b.offset)/b.scale;}
}
