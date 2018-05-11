#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 题目描述
// LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
//他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,
//嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,
//决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
//上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
//现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。



class Solution{
public: 

    //A方案
    //1. 除0外没有重复的数
    //2. max - min < 5 
    // bool IsContinuous( vector<int> numbers ) {
    //     if(numbers.size()!=5)
    //         return false;
    //     sort(numbers.begin(),numbers.end());
    //     int min = 0;
    //     for(int i = 0;i<5;i++)
    //     {
    //         if(numbers[i]!=0)
    //         {
    //             min = numbers[i];
    //             break;
    //         }
    //     }    
    //     if(numbers[4]-min>=5)
    //         return false;
    //     for(int i =0;i<4;i++)
    //     {
    //         if(numbers[i]!=0&&numbers[i]==numbers[i+1])
    //             return false;
    //     }

    //     return true;
        
    // }
    //B方案
    //步骤：
    //1.统计0个数
    //2.统计不连续数字个数(并且不可以有重复数字，除0以外)
    bool IsContinuous(vector<int> numbers) {
        if(numbers.size()!=5)
            return false;
        sort(numbers.begin(),numbers.end());
        int zeronum = 0;
        int gapnum = 0;
        for(int i =0;i<5;i++)
            if(numbers[i]==0)
                zeronum++;
        int small = zeronum;
        int big = small+1;
        for(int i =small;i<4;i++)
        {
            if(numbers[small]==numbers[big])
                return false;
            gapnum += numbers[big]-numbers[small]-1;
            small = big;
            ++big;
        }
        return gapnum<=zeronum?true:false;
    }
};