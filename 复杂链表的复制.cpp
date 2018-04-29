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

class Solution {
public:
	/*
	1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
	2、遍历链表，A1->random = A->random->next;
	3、将链表拆分成原链表和复制后的链表
	*/

	RandomListNode* Clone(RandomListNode* pHead)
	{
		//刚开始还没有random 所以需要分三步
		if (!pHead) return NULL;
		RandomListNode *currNode = pHead;
		while (currNode) {
			RandomListNode *node = new RandomListNode(currNode->label);
			node->next = currNode->next;
			currNode->next = node;
			currNode = node->next;
		}
		currNode = pHead;
		while (currNode) {
			RandomListNode *node = currNode->next;//注意新复制链表其实是2，4，6，8
			if (currNode->random) {
				node->random = currNode->random->next;
			}
			currNode = node->next;
		}
		//拆分
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *tmp;
		currNode = pHead;
		//2 4
	
		while (currNode->next){
			tmp = currNode->next;//2节点记下
			currNode->next = tmp->next;//1和3连接起来
			currNode = tmp;//2   
			//3 节点记下来
			//2和4连接起来
			//3
		}
		return pCloneHead;
	}
};