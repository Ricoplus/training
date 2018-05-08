#include<iostream>
#include<vector>
using namespace std;
// 题目描述
// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
//但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
         vector<vector<int>> v;
         int start = 1,end=2;
         int mid = (1+sum)/2;
         while(start<mid)
         {
             int cur = ((end-start+1)*(start+end))>>1;
             //扩大范围
             if(cur<sum)
             {
                 end++;
             }
             if(cur==sum)
             {
                 vector<int> tmp;
                 
                 for(size_t i = start; i <= end; i++)
                 {
                     tmp.push_back(i);
                 }
                 v.push_back(tmp);
                 start++;
             }
             //缩小范围
             if(cur>sum)
             {
                 start++;
             }
         }    
         return v;
    }
};
