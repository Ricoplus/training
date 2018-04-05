

//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
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
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* next = head;
		while (head)
		{
			next = head->next
			head->next = prev;
			prev = head;
			head = next;
		}
		vector<int> v;
		while (prev)
		{
			v.push_back(prev->val);
			prev = prev->next;
		}
		return v;


	}
};