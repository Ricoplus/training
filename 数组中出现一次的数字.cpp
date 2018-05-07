#include<iostream>
#include<vector>
using namespace std;
// 题目描述
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

// 如果将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或
// 的结果，所以根据异或的结果1所在的最低位，把数字分成两半，每一半里都还有只出现一次的数据和成对出现的数据
// 这样继续对每一半相异或则可以分别求出两个只出现一次的数字
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()==0)
            return;
        //存储异或结果
        int tmp = 0;
        *num1 = 0,*num2=0;
        for(size_t i = 0;i<data.size();i++)
        {
            tmp = tmp^data[i]; 
        }
        int index = 0;
        while(tmp)
        {
            if(tmp&(1<<index))
                break;
            ++index;
        }
        for(size_t i = 0;i<data.size();i++)
        {
            if(data[i]&(1<<index))
                *num1 = *num1^data[i];
            else
                *num2 = *num2^data[i];
        }
        return;

    }
};