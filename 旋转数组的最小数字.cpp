//��Ŀ����
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	int minNumberInRotateArray(vector<int> a) {
		if (a.size() == 0)
			return 0;

		int left = 0;
		int right = a.size() - 1;


		//ȷ���Ǹ���ת����
		while (a[left] >= a[right])
		{
			if (left + 1 == right)
				break;
			int mid = (left + right) / 2;
			if (a[left] == a[right] && a[right] == a[mid])
				return MinNumber(a, left, right);
			if (a[left] <= a[mid])
				left = mid;
			else if (a[left] > a[mid])
				right = mid;
		}

		return a[right];

	}

	int MinNumber(vector<int> a, int left, int right)
	{
		int min = a[left];
		for (int i = left; i < right + 1; i++)
		{
			if (min > a[i])
				min = a[i];
		}
		return min;
	}

};