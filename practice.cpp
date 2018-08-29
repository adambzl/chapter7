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

//�������еľ�̬��Ա����
//�������еķǳ������г�ʼ��
double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

void countWords() {
	//ͳ������ĵ�����������is are was were
	string word;
	map<string, size_t> words;
	set<string> excluded_words = { "is", "are", "was" };
	excluded_words.insert("were");
	cout << "������Ҫͳ�Ƶ�����:" << endl;
	while (cin >> word)
		if (excluded_words.find(word) == excluded_words.end())
			words[word] ++;
	for (const auto record : words)
		cout << record.first << "������" << record.second << "��" << endl;
	return;
}

vector<int> twoSum(vector<int>& nums, int target) {
	//����һ����ϣ�������ͬʱ���һ���Ԫ���Ƿ���ڣ������ӶȽ�ΪO(n)
	//stupid program that fucks me
	map<int, int> m;
	vector<int> result;
	auto iter = nums.cbegin();
	for (; iter != nums.cend(); iter++) {
		if (iter != nums.cbegin()) {
			int temp = target - *iter;
			if (m.find(temp) != m.end()) {
				//������ظ�ƥ�䣬��ô�������ֻ���ҵ����һ��ƥ����ֵ�λ��
				result.push_back(m[temp]);
				result.push_back(iter - nums.cbegin());
				return result;
			}
		}
		//��ƥ����ߵ�һ��Ԫ�ص��������map�в�����Ԫ��
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
	//v�д洢���ַ����е�ÿһ���ַ��ڵ�ǰ�����������һ�γ��ֵ�λ��
	int beg = 0, len = 0;
	//beg��¼��ǰ�Ӵ������￪ʼ
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i]] >= beg)
			beg = v[s[i]] + 1;
		//��ǰ�ַ���֮ǰ������·���ϳ��ֹ�
		//���beg <= ��λ�ã���ô������ȡ�����ַ����н������ظ��ַ������begӦ������Ϊ��λ��+1
		//���ڵ�ǰλ��֮ǰ����Ӵ����ȶ��Ѿ�������˲��Ҽ�¼��len֮�У����������������©
		//***�������Ϊ��i��ÿһ��λ�ã���ǰȥ������ظ��ַ���***
		v[s[i]] = i;
		//���¸��ַ����һ�γ��ֵ�λ��Ϊ��ǰ������
		if (len < i - beg + 1)
			len = i - beg + 1;
	}
	return len;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//��������A�ĳ���Ϊm������B�ĳ���Ϊn
	//һ����ʵ����λ����һ���������зֳ��˵ȳ��������ֶ����ұߵ��ܱ���ߵĴ�
	//�����±�i�����ⳤ��Ϊn������C��Ϊ��������C[0]...C[i - 1]��C[i]...C[n - 1]
	//�����λ������ʵ�����Խ�����Ŀ������Ϊ
	//�ҵ����ֵ�i��j�����������Ϊ����������A[0]...A[i - 1],B[0]...B[j - 1]��A[i]...A[m - 1]��B[j]...B[n - 1]������A[i - 1] <= B[j]����B[j - 1] <= A[i]
	//ʹ��i + j = m - i + n - j����m + nΪż��)��i + j = m - i + n - j + 1����m + nΪ������
	//��������������¶���j = (m + n + 1)/2 - i��ͬʱ���ǵ�0 <= i <= m��0 <= j <= n���ʱ�����n >= m
	//��i��������
	//���Ǽ��������������i = 0��j = n����ô����A����벿�ֻ��ֻ�����B���Ұ벿�ֻ��ֲ����ڣ���˲���Ҫȥ�ж�A[i - 1] <= B[j]������i = m��j = n���������
	//��i > 0��i < m����j�ı��ʽһ�������Ƶ���j < n�� j > 0

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
				//��Ԫ����Ϊ������������벿��Ԫ�ص����ֵ
				if (i == 0)
					return B[j - 1];
				else if (j == 0)
					return A[i - 1];
				else
					return A[i - 1] >= B[j - 1] ? A[i - 1] : B[j - 1];
			}
			else {
				//���򣬷�����벿��Ԫ�ص����ֵ���Ұ벿��Ԫ����Сֵ��ƽ��ֵ
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
			//˵��iӦ�ü�С����Ӧ��jҲ��֮����
			//��Χ���ж���Ϊ�˷�ֹ�����±�Խ�磬�����ٽ�ֵ���������������
			right = i - 1;
		}
		else
			left = i + 1;
	}
}