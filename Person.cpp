#include "Person.h"
using std::istream;
using std::ostream;


Person::Person(istream &in):Person::Person() {
	read(in, *this);
}
//�˹��캯�������ʼ���б���ָ����һ�������캯��
//�����캯�������ڱ������ķ�����ִ��

istream& read(istream &in, Person &person) {
	getline(in, person.name);
	getline(in, person.address);
	return in;
}

ostream& print(ostream &out, const Person &person) {
	out << person.name << " : " << person.address;
	//����ຯ��Ӧ������ٵĸ�ʽ
	return out;
}
