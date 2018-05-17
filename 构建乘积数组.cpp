#include<vector>
#include<iostream>
using namespace std;

// 题目描述
// 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
//其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。

//想成两个三角形 一个上三角 一个下三角
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.size()==0)
            return A;
        int size = A.size();
        vector<int> B(size);
        B[0] = 1;
        for(int i = 1; i < size; i++)
        {
            B[i]=A[i-1]*B[i-1];
        }
        int tmp = 1;
        for(int i = size-2; i >= 0; i--)
        {
            tmp=tmp*A[i+1];
            B[i] = B[i]*tmp;
        }
        return B;
    }
};