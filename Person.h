#include <string>
#ifndef _Person
#define _Person
class Person {
private:
	std::string name;
	std::string address;

public:
	std::string getName() const {
		//constʹthisָ��ͬʱ�ǳ���ָ�룬��֤����������Ե��ô˺���
		return name;
	}
	std::string getAddress() const {
		return address;
	}

	Person() = default;
	//����ʱͨ��default����Ĭ����Ϊ�������ɱ������Զ�����
	//����in-class initializer��ʹ�����ʼ��
	//�������Ĭ�ϳ�ʼ��
	Person(std::istream &in);
	Person(const std::string &name_in, const std::string &address_in):name(name_in), address(address_in){}

	friend std::istream& read(std::istream &in, Person &person);
	friend std::ostream& print(std::ostream &out, const Person& person);
	//���������Ԫ������ʹ֮�������ɷ�����ķ�public��Ա
	//��������������ķǳ�Ա�����Ľӿں���
};

std::istream& read(std::istream &in, Person &person);
std::ostream& print(std::ostream &out, const Person& person);
//read��print��������صķǳ�Ա�����Ľӿں��������ǵ�����Ӧ�ú������һ��ͷ�ļ�֮��
//istream��ostream��Ķ��󶼲����Ա����ƣ����ֻ�ܴ��ݻ򷵻����ǵ�����
#endif