#include<iostream>
using namespace std;
//��Ŀ����
//����=2^x*3^y*5^z;
//Ҫע�⣬����ĳ�������ǰһ����������2��3��5�е�һ����������˿����ö�̬�滮ȥ��
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		vector<int> v(index);
		v[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;

		for (size_t i = 1; i < index; i++)
		{
			v[i] = min(v[t2]*2,min(v[t3]*3,v[t5]*5));
			if (v[i] == v[t2] * 2) t2++;
			if (v[i] == v[t3] * 3) t3++;
			if (v[i] == v[t5] * 5) t5++;
		}
		return v[index - 1];
	}
};