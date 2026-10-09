#pragma once
#include <memory>
#include <string>
#include <vector>
namespace axf {
struct MenuItem { std::string id,label,command; std::vector<MenuItem> children; };
struct Menu { std::string title; std::vector<MenuItem> items; };
std::unique_ptr<Menu> make_main_menu();
}
