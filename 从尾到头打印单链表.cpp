

//输入一个链表，从尾到头打印链表每个节点的值。
#include<vector>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		, next(NULL) 
	{}
};

class Solution {
public:
	//1.递归
	/*void Print(vector<int>& v, ListNode* cur)
	{
		if (cur == NULL)
			return;
		Print(v,cur->next);
		v.push_back(cur->val);
	}
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		Print(v, head);
		return v;
	}*/
	//2.利用反向迭代器
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}
		vector<int> tmp(v.rbegin(),v.rend());
		return v;
	}

};
