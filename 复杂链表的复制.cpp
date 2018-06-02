#include<iostream>
using namespace std;


//��Ŀ����
//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
//���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�



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
	1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
	2����������A1->random = A->random->next;
	3���������ֳ�ԭ����͸��ƺ������
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