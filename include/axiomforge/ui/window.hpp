#pragma once
#include <string>
#include <utility>
namespace axf {
struct WindowSpec { std::string title; int width{1280}; int height{800}; bool resizable{true}; };
class WindowModel { public: explicit WindowModel(WindowSpec spec):spec_(std::move(spec)){} const WindowSpec& spec()const{return spec_;} private: WindowSpec spec_; };
}
