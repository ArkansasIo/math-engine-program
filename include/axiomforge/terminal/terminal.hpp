#pragma once
#include <functional>
#include <string>
namespace axf {
class Terminal {
public:
 using Handler=std::function<std::string(const std::string&)>;
 explicit Terminal(Handler handler):handler_(std::move(handler)){}
 void run();
private: Handler handler_;
};
}
