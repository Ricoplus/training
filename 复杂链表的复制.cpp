#include<iostream>
using namespace std;


//题目描述
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）



struct RandomListNode{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) 
		:label(x)
		,next(NULL)
		,random(NULL) 
	{}
};


	/*
	1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
	2、遍历链表，A1->random = A->random->next;
	3、将链表拆分成原链表和复制后的链表
	*/
class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* cur = pHead;
		while (cur)
		{
			RandomListNode* tmp = new RandomListNode(cur->label);
			tmp->next = cur->next;
			cur->next = tmp;
			cur = tmp->next;
		}
		cur = pHead;
		while(cur)
		{
			RandomListNode* next = cur->next;
			if(cur->random)
				next->random = cur->random->next;
			cur = next->next;
		}
		cur = pHead;
		RandomListNode* head = cur->next;
		RandomListNode* tmp = cur->next;
		//1 2 3 4
		while (tmp)
		{
			cur->next = tmp->next;
			cur = tmp;
			tmp = tmp->next;
		}
		return head;
	}
};