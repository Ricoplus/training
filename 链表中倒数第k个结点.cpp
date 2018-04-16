#include<iostream>
#include<vector>
using namespace std;

//题目描述
//输入一个链表，输出该链表中倒数第k个结点。


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL)
	{}
};
//制造了一个K长度的尺子, 把尺子从头往后移动, 当尺子的右端与链表的末尾对齐的时候，尺子左端所在的结点就是倒数第k个结点！
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k < 0)
			return NULL;

		ListNode* pre = pListHead;
		ListNode* last = pListHead;
		while (k--)
		{
			last = last->next;
			if (last==NULL)
				return NULL;
		}
		while (last->next)
		{
			pre = pre->next;
			last = last->next;
		}
		return pre;
		/*if (pListHead == NULL)
			return NULL;
		vector<ListNode*> v;
		ListNode* cur = pListHead;
		while (cur)
		{
			v.push_back(cur);
			cur = cur->next;
		}
		if (v.size() - k >= v.size())
			return NULL;
		return v[v.size() - k];*/
	}
};
