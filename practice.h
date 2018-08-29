#include <vector>
#ifndef _pra1
#define _pra1
class Y;
class X {
	Y *y;
	//仅被声明而未定义的类是不完整的类型，只能使用其引用或指针，或是在函数声明中使用这些对象
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