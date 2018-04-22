#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
//���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//�����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.




class Solution {
public:
	vector<int> printMatrix(vector<vector<int>> matrix) {

		vector<int> v;
		int row = matrix.size();
		int col = matrix[0].size();
		if (row == 0 || col == 0)
			return v;
		int left = 0,top = 0, right = col - 1,bottom = row - 1 ;
		while (left<=right&&top<=bottom)
		{
			//��ߵ��ұ�
			for (int i = left; i <= right; i++)
				v.push_back(matrix[top][i]);
			//���浽�±�
			for (int i = top + 1; i <=bottom; i++)
				v.push_back(matrix[i][right]);
			//�ұߵ����
			if(top!=bottom)//��ֹ����
			for (int i = right - 1; i >= left; i--)
				v.push_back(matrix[bottom][i]);
			//�±ߵ��ϱ�

			if(left!=right)//��ֹ����
			for (int i = bottom-1; i> top; i--)
				v.push_back(matrix[i][left]);
			left++; top++; right--;  bottom--;
		}
		return v;
	}
};

