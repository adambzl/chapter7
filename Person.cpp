#include "Person.h"
using std::istream;
using std::ostream;


Person::Person(istream &in) {
	read(in, *this);
}

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
