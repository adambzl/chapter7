#include <vector>
#ifndef _pra1
#define _pra1
class Y;
class X {
	Y *y;
	//����������δ��������ǲ����������ͣ�ֻ��ʹ�������û�ָ�룬�����ں���������ʹ����Щ����
};

class Y {
	X x;
};
#endif
#ifndef _ListNode
#define _ListNode
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};
#endif
void countWords();
std::vector<int> twoSum(std::vector<int>& nums, int target);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int lengthOfLongestSubstring(std::string s);

#ifndef _Example
#define _Example

class Example {
public:
	static double rate;
	static const int vecSize = 20;
	static std::vector<double> vec;
};

#endif