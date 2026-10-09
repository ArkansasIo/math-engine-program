#pragma once
#ifdef _WIN32
#include <windows.h>
namespace ui1024 { class Virtual1024App { HWND hwnd_{}; int tick_{}; public: bool create(HINSTANCE); int run(); static LRESULT CALLBACK wnd_proc(HWND,UINT,WPARAM,LPARAM); LRESULT paint(HDC); }; }
#endif