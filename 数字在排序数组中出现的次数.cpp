#include<iostream>
#include<vector>
using namespace std;
// 题目描述
// 统计一个数字在排序数组中出现的次数。


//A解法
//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
// class Solution {
// public:
//     //记得一定是double
//     int getIndex(vector<int>& a,double num)
//     {
//         int left = 0,right = a.size()-1;
//         //lefy<=right
//         while(left<=right)
//         {
//             int mid = (left+right)/2;
//             if(a[mid]<num)
//                 left = mid+1;
//             else if(a[mid]>num)
//                 right = mid-1;
//         }
//         return left;
//     }
//     int GetNumberOfK(vector<int> data ,int k) {
//         if(data.size()==0)
//             return 0;
        
//         return getIndex(data,k+0.5)-getIndex(data,k-0.5);
//     }
// };

//B解法
//排序所以一定要用二分查找 获取第一个位置和最后一个位置最后相减加一
class Solution {
public:
    //记得一定是double
    int GetFirst(vector<int>& a,int num)
    {
        int left = 0,right = a.size()-1;
        //lefy<=right
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(a[mid]<num)
                left = mid+1;
            else if(a[mid]>num)
                right = mid-1;
            else if(mid-1>=left&&a[mid-1]==num)
                right = mid-1;
            else
                return mid;
        }
        return 0;
    }
    int GetLast(vector<int>& a,int num)
    {
        int left = 0,right = a.size()-1;
        //lefy<=right
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(a[mid]<num)
                left = mid+1;
            else if(a[mid]>num)
                right = mid-1;
            else if(mid+1<=right&&a[mid+1]==num)
                left = mid+1;
            else
                return mid;
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)
            return 0;
        int first = GetFirst(data,k);
        int last = GetLast(data,k);
        if(first<0||last<0)
            return 0;
        return last-first+1;
    }
};