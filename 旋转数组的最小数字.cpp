//题目描述
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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


		//确保是个旋转数组
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