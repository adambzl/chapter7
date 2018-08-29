#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "practice.h"

using std::set;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//定义类中的静态成员变量
//并对其中的非常量进行初始化
double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

void countWords() {
	//统计输入的单词数，忽略is are was were
	string word;
	map<string, size_t> words;
	set<string> excluded_words = { "is", "are", "was" };
	excluded_words.insert("were");
	cout << "请输入要统计的内容:" << endl;
	while (cin >> word)
		if (excluded_words.find(word) == excluded_words.end())
			words[word] ++;
	for (const auto record : words)
		cout << record.first << "出现了" << record.second << "次" << endl;
	return;
}

vector<int> twoSum(vector<int>& nums, int target) {
	//建立一个哈希表，插入的同时查找互补元素是否存在，将复杂度降为O(n)
	//stupid program that fucks me
	map<int, int> m;
	vector<int> result;
	auto iter = nums.cbegin();
	for (; iter != nums.cend(); iter++) {
		if (iter != nums.cbegin()) {
			int temp = target - *iter;
			if (m.find(temp) != m.end()) {
				//如果有重复匹配，那么这个程序只能找到最后一次匹配出现的位置
				result.push_back(m[temp]);
				result.push_back(iter - nums.cbegin());
				return result;
			}
		}
		//无匹配或者第一个元素的情况则向map中插入新元素
		m[*iter] = iter - nums.cbegin();
	}
	return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *add1 = l1;
	ListNode *add2 = l2;
	ListNode *result = nullptr, *pos = nullptr;
	int temp = 0;
	while (add1 || add2 || temp) {
		if (add1) {
			temp += add1->val;
			add1 = add1->next;
		}
		if (add2) {
			temp += add2->val;
			add2 = add2->next;
		}
		if (!result) {
			result = new ListNode(temp % 10);
			pos = result;
		}
		else {
			pos->next = new ListNode(temp % 10);
			pos = pos->next;
		}
		temp = temp / 10;
	}
	return result;
}

int lengthOfLongestSubstring(string s) {
	vector<int> v(255, -1);
	//v中存储着字符串中的每一个字符在当前搜索点上最后一次出现的位置
	int beg = 0, len = 0;
	//beg记录当前子串从哪里开始
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i]] >= beg)
			beg = v[s[i]] + 1;
		//当前字符在之前的搜索路径上出现过
		//如果beg <= 该位置，那么最终提取到的字符串中将包含重复字符，因此beg应该设置为该位置+1
		//由于当前位置之前的最长子串长度都已经考察过了并且记录在len之中，因此这样做不会遗漏
		//***可以理解为在i的每一个位置，向前去找最长无重复字符串***
		v[s[i]] = i;
		//更新该字符最后一次出现的位置为当前搜索点
		if (len < i - beg + 1)
			len = i - beg + 1;
	}
	return len;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//假设数组A的长度为m，数组B的长度为n
	//一个事实是中位数将一个有序序列分成了等长的两部分而且右边的总比左边的大
	//假设下标i将任意长度为n的数组C分为两个序列C[0]...C[i - 1]和C[i]...C[n - 1]
	//结合中位数的事实，可以将程序目标设置为
	//找到划分点i和j将两个数组分为左右两部分A[0]...A[i - 1],B[0]...B[j - 1]和A[i]...A[m - 1]和B[j]...B[n - 1]，而且A[i - 1] <= B[j]并且B[j - 1] <= A[i]
	//使得i + j = m - i + n - j（若m + n为偶数)或i + j = m - i + n - j + 1（若m + n为奇数）
	//不论在哪种情况下都有j = (m + n + 1)/2 - i，同时考虑到0 <= i <= m和0 <= j <= n，故必须有n >= m
	//对i搜索即可
	//考虑几种特殊情况：若i = 0或j = n，那么数组A的左半部分划分或数组B的右半部分划分不存在，因此不需要去判断A[i - 1] <= B[j]；对于i = m和j = n的情况类似
	//若i > 0或i < m，由j的表达式一定可以推导出j < n或 j > 0

	int m = nums1.size() <= nums2.size() ? nums1.size() : nums2.size();
	vector<int> &A = nums1.size() <= nums2.size() ? nums1 : nums2;
	int n = nums1.size() <= nums2.size() ? nums2.size() : nums1.size();
	vector<int> &B = nums1.size() <= nums2.size() ? nums2 : nums1;
	int i, j;
	int left = 0, right = m;
	i = (left + right) / 2;
	while (1) {
		i = (left + right) / 2;
		j = (m + n + 1) / 2 - i;
		if (((i == 0 || j == n) || (A[i - 1] <= B[j])) && ((i == m || j == 0) || (B[j - 1] <= A[i]))) {
			if ((m + n) % 2 != 0) {
				//总元素数为奇数，返回左半部分元素的最大值
				if (i == 0)
					return B[j - 1];
				else if (j == 0)
					return A[i - 1];
				else
					return A[i - 1] >= B[j - 1] ? A[i - 1] : B[j - 1];
			}
			else {
				//否则，返回左半部分元素的最大值和右半部分元素最小值的平均值
				int max, min;
				if (i == 0)
					max = B[j - 1];
				else if (j == 0)
					max = A[i - 1];
				else
					max = A[i - 1] >= B[j - 1] ? A[i - 1] : B[j - 1];
				if (i == m)
					min = B[j];
				else if (j == n)
					min = A[i];
				else
					min = A[i] <= B[j] ? A[i] : B[j];
				return (min + max) / 2.0;
			}
		}
		else if (i > 0 && i < m && A[i - 1] > B[j]) {
			//说明i应该减小，相应地j也随之增大
			//范围的判定是为了防止数组下标越界，考虑临界值不满足条件的情况
			right = i - 1;
		}
		else
			left = i + 1;
	}
}