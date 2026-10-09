#pragma once
#include <string>
namespace axf {
struct Vec2 { float x{},y{}; };
struct Color { float r{1},g{1},b{1},a{1}; };
class Renderer {
public:
 virtual ~Renderer()=default;
 virtual void begin_frame()=0;
 virtual void draw_text(Vec2 position,const std::string& text,Color color={})=0;
 virtual void draw_line(Vec2 from,Vec2 to,Color color={})=0;
 virtual void end_frame()=0;
};
}
