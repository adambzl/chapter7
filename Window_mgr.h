#include <vector>
#include "Screen.h"
#ifndef _Window_mgr
#define _Window_mgr

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
private:
	std::vector<Screen> v;
public:
	void clear(ScreenIndex index) {
		Screen &screen = v[index];
		screen.contents = "";
		//Window_mgr已经声明为类的友元类，因此可以自由使用类的所有成员
	}
};

#endif