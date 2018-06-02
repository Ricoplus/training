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
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (k == 0 || pListHead == NULL)
			return NULL;
		
		ListNode* cur = pListHead;
		//问题在于当是正着数第一个会有问题 直接会返回空 所以--k 不是k--
		while (--k)
		{
			cur = cur->next;
			if (cur == NULL)
				return NULL;
		}
		while (cur->next)
		{
			pListHead = pListHead->next;
			cur = cur->next;
		}
		return pListHead;
	}
};