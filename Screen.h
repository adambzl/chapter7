#include <string>
#ifndef _Screen
#define _Screen
//以上预处理语句有两个作用，倘若在类内定义了成员函数(对应了内存中的代码空间)
//那么没有以上语句很容易出现：
//1.同一头文件在一个源文件中多次包含(展开后是平行关系)导致一个源文件中对象重定义
//2.不同源文件中定义了相同的对象实体导致连接时出现错误(注意预处理器变量是全局的)
//声明是声明给编译器看的，定义是分配内存空间的过程

class Screen {
	friend class Window_mgr;//声明友元函数或类时不需要事先定义或声明，但是使用时需要
public:
	using pos = std::string::size_type;
	//在类中定义的类型，要求在使用之前出现
	//同样符合访问控制规则
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
public:
	Screen() = default;
	Screen(pos c = 0, pos w = 0, pos h = 0, const std::string &s = ""):cursor(c), width(w), height(h), contents(s){}
	char get() const { return contents[cursor]; }
	char get(pos row, pos offset) const;
	//不改变对象内容的成员函数应该作为const
	Screen& move(pos row, pos offset);
};

inline char Screen::get(pos row, pos offset) const {
	return contents[row * width + offset];
}

inline Screen& Screen::move(pos row, pos offset) {
	cursor = width * row + offset;
	return *this;
}
//内联的类的成员函数也应该放置在头文件中
#endif

