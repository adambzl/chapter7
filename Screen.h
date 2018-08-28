#include <string>
#ifndef _Screen
#define _Screen
//����Ԥ����������������ã����������ڶ����˳�Ա����(��Ӧ���ڴ��еĴ���ռ�)
//��ôû�������������׳��֣�
//1.ͬһͷ�ļ���һ��Դ�ļ��ж�ΰ���(չ������ƽ�й�ϵ)����һ��Դ�ļ��ж����ض���
//2.��ͬԴ�ļ��ж�������ͬ�Ķ���ʵ�嵼������ʱ���ִ���(ע��Ԥ������������ȫ�ֵ�)
//���������������������ģ������Ƿ����ڴ�ռ�Ĺ���

class Screen {
	friend class Window_mgr;//������Ԫ��������ʱ����Ҫ���ȶ��������������ʹ��ʱ��Ҫ
public:
	using pos = std::string::size_type;
	//�����ж�������ͣ�Ҫ����ʹ��֮ǰ����
	//ͬ�����Ϸ��ʿ��ƹ���
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
	//���ı�������ݵĳ�Ա����Ӧ����Ϊconst
	Screen& move(pos row, pos offset);
};

inline char Screen::get(pos row, pos offset) const {
	return contents[row * width + offset];
}

inline Screen& Screen::move(pos row, pos offset) {
	cursor = width * row + offset;
	return *this;
}
//��������ĳ�Ա����ҲӦ�÷�����ͷ�ļ���
#endif

