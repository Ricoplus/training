#include<iostream>
using namespace std;
//��Ŀ����
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���


//base ==0 ��ʱû���� Ҳ����ac ����oj��bug
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		int flag = 1;
		if (exponent < 0)
		{
			exponent = -1 * exponent;
			flag = -1;
		}
		double sum = 1;
		while (exponent--)
		{
			sum = sum*base;
		}
		if (flag == -1)
			sum = 1 / sum;
		return sum;

	}
};