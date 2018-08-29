#include "Person.h"
using std::istream;
using std::ostream;


Person::Person(istream &in):Person::Person() {
	read(in, *this);
}
//此构造函数在其初始化列表中指定了一个代理构造函数
//代理构造函数会先于本方法的方法体执行

istream& read(istream &in, Person &person) {
	getline(in, person.name);
	getline(in, person.address);
	return in;
}

ostream& print(ostream &out, const Person &person) {
	out << person.name << " : " << person.address;
	//输出类函数应输出最少的格式
	return out;
}
