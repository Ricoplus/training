#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
class Solution {
public:
	//O(N*lgN)
	//int MoreThanHalfNum_Solution(vector<int> numbers) {
	//	sort(numbers.begin(), numbers.end());
	//	int target = numbers[numbers.size() / 2];
	//	int count = 0;
	//	for (size_t i = 0; i < numbers.size(); i++)
	//	{
	//		if (numbers[i] == target)
	//			++count;
	//	}
	//	if (count > (numbers.size() / 2))
	//		return target;
	//	else
	//		return 0;
	//}
	
	//O(N)


	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int num = numbers[0],count = 1;

		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == num)
				count++;
			else
				count--;
			if (count == 0)
			{
				num = numbers[i];
				count = 1;
			}
		}
		count = 0;
		for (size_t i = 0; i < numbers.size(); i++)
			if (numbers[i] == num)
				count++;

		return count > (numbers.size() / 2) ? num : 0;
	}



};