#pragma once
#include <cstdint>
#include <string>
namespace axf { using Integer=std::int64_t; Integer add(Integer a,Integer b); Integer subtract(Integer a,Integer b); Integer multiply(Integer a,Integer b); std::string classify(Integer n); }
