#include "ui/Virtual1024App.hpp"
#ifdef _WIN32
int WINAPI wWinMain(HINSTANCE h,HINSTANCE,LPWSTR,int){ui1024::Virtual1024App app;return app.create(h)?app.run():1;}
#endif