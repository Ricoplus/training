#include<iostream>
using namespace std;

//��Ŀ����
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
class Solution {
public:
	int  NumberOf1(int n) {
		int sum = 0;

		if (n < 0)
		{
			n = n & 0X7FFFFFFF;
			sum++;
		}
		/*
		int i = 31;
		while (i>=0)
		{
		sum += (n& (1<<i))>>i;
		i--;
		}*/
		//���Žⷨ
		while (n != 0)
		{
			sum += n & 1;
			n = n >> 1;
		}
		return sum;
	}
};