#include "axiomforge/graphics/renderer.hpp"
#include <iostream>
namespace axf {
class MockRenderer final:public Renderer {
public:
 void begin_frame()override{std::cout<<"[frame begin]\n";}
 void draw_text(Vec2 p,const std::string&t,Color)override{std::cout<<"text("<<p.x<<","<<p.y<<"): "<<t<<'\n';}
 void draw_line(Vec2 a,Vec2 b,Color)override{std::cout<<"line("<<a.x<<","<<a.y<<" -> "<<b.x<<","<<b.y<<")\n";}
 void end_frame()override{std::cout<<"[frame end]\n";}
};
}
