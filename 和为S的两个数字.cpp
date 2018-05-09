#include<iostream>
#include<vector>
using namespace std;
// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。
// 输出描述:

// 对应每个测试案例，输出两个数，小的先输出。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> v,int sum) {
        vector<int> tmp;
        if(v.size()==0)
            return tmp;
        int start = 0,end=v.size()-1;
        while(start<end)
        {
            int cur =v[start]+v[end];
            if(cur<sum)
            {
                start++;
            }
            if(cur==sum)
            {
               tmp.push_back(v[start]);
               tmp.push_back(v[end]);
               
               break;
            }
            if(cur>sum)
                end--;
        }
        return tmp;
    }
};