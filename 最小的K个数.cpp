#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//题目描述
//输入n个整数，找出其中最小的K个数。例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4, 。
class Solution {
public:
	//1.快速排序思想 
	int P(vector<int>& a, int left, int right)
	{
		int index = right;
		while (left < right)
		{
			while (left < right&&a[left] <= a[index])
				left++;
			while (left < right&&a[right] >= a[index])
				right--;

			swap(a[left], a[right]);
		}
		swap(a[left], a[index]);
		return left;
	}
	void Q(vector<int>& a, int left, int right, int k)
	{
		if (left > right)
			return;

		int mid = P(a, left, right);
		if (mid == k)
			return;
		else if (mid>k)
			Q(a, left, mid - 1, k);
		else
			Q(a, mid + 1, right, k);

	}


	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> v;

		if (input.empty() || k > input.size())
			return v;
		Q(input, 0, input.size() - 1, k);
		for (size_t i = 0; i < k; i++)
		{
			v.push_back(input[i]);
		}
		sort(v.begin(), v.end());
		return v;
	}
	//2.全排序
	//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	//	vector<int> v;

	//	if (input.size() == 0||k>input.size())
	//		return v;
	//	sort(input.begin(), input.end());
	//	for (size_t i = 0; i < k; i++)
	//		v.push_back(input[i]);
	//	return v;
	//}
	//3.最大堆
	//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	//	priority_queue<int> q(input.begin(),input.begin()+k);
	//	for (size_t i = k; i < input.size(); i++)
	//	{
	//		if (input[i] < q.top())
	//		{
	//			q.pop();
	//			q.push(input[i]);
	//		}
	//	}
	//	vector<int> v;
	//	for (size_t i = 0; i < k; i++)
	//	{
	//		v.push_back(q.top());
	//		q.pop();
	//	}
	//	sort(v.begin(), v.end());
	//	return v;
	//}
	//	void AdjustDown(vector<int>& a, int parent, int size)
	//	{
	//		int child = parent * 2 + 1;
	//		while (child < size)
	//		{
	//			while (child + 1 < size&&a[child + 1] > a[child])
	//				child++;
	//			if (a[child] > a[parent])
	//			{
	//				swap(a[child], a[parent]);
	//				parent = child;
	//				child = parent * 2 + 1;
	//			}
	//			else
	//				break;
	//		}
	//		return;
	//	}
	//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	//		vector<int> minheap(input.begin(), input.begin() + k);
	//
	//		for (int j = (k - 2) / 2; j >= 0; j--)
	//			AdjustDown(minheap, j, k);
	//
	//		for (size_t i = k; i < input.size(); i++)
	//		{
	//			if (input[i] < minheap[0])
	//			{
	//				swap(input[i], minheap[0]);
	//				AdjustDown(minheap, 0, k);
	//			}
	//		}
	//		sort(minheap.begin(), minheap.end());
	//		return minheap;
	//	}
};
