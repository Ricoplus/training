#include<iostream>
using namespace std;
//��Ŀ����
//���1~13��������1���ֵĴ���, �����100~1300��������1���ֵĴ�����
//Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
//���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����, ������������ձ黯, 
//���Ժܿ���������Ǹ�����������1���ֵĴ�����

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{

		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i��ʾ��ǰ����������һ����λ
			int a = n / i, b = n % i;
			count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};