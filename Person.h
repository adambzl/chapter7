#include <string>
#ifndef _Person
#define _Person
class Person {
private:
	std::string name;
	std::string address;

public:
	std::string getName() const {
		//const使this指针同时是常量指针，保证常量对象可以调用此函数
		return name;
	}
	std::string getAddress() const {
		return address;
	}

	Person() = default;
	//声明时通过default表明默认行为，定义由编译器自动生成
	//若有in-class initializer则使用其初始化
	//否则采用默认初始化
	Person(std::istream &in);
	Person(const std::string &name_in, const std::string &address_in):name(name_in), address(address_in){}

	friend std::istream& read(std::istream &in, Person &person);
	friend std::ostream& print(std::ostream &out, const Person& person);
	//声明类的友元函数，使之可以自由访问类的非public成员
	//它们往往用于类的非成员函数的接口函数
};

std::istream& read(std::istream &in, Person &person);
std::ostream& print(std::ostream &out, const Person& person);
//read和print是与类相关的非成员函数的接口函数，它们的声明应该和类放在一个头文件之中
//istream和ostream类的对象都不可以被复制，因此只能传递或返回它们的引用
#endif