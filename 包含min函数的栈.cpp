#include<iostream>
#include<list>
using namespace std;
//��Ŀ����
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
class Solution {
	list<int> l1;
	list<int> l2;
public:
	void push(int value) {
		if (l1.size() == 0)
		{
			l1.push_back(value);
			l2.push_back(value);
		}
		else
		{
			if (value > l2.back())
				l2.push_back(l2.back());
			else
				l2.push_back(value);
			
			l1.push_back(value);
		}
	}
	void pop() {
		if (l1.size() == 0)
			return;
		l1.pop_back();
		l2.pop_back();

	}
	int top() {
		if (l1.size() == 0)
			return 0;
		return l1.back();
	}
	int min() {
		if (l1.size() == 0)
			return 0;
		return l2.back();

	}
};