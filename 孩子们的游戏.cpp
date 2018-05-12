#include<iostream>
#include<vector>
using namespace std;

//题目描述
//每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
//HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
//首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
//每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
//从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
//可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
//请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
class Solution{
public:
    int LastRemaining_Solution(int n,int m)
    {
        //异常情况考虑
        if (n <1 || m < 1)
            return -1;
        vector<bool>  v(n,false);
        //index = -1 一下让操作统一起来
        int count  = 0,index = -1,step = 0;
        //退出时候所有都被置成-1 index指向的是最后一个被置为-1的
        while(count<n)
        {
            index++;//指向上一个被删除对象的下一个元素。
            if(index>=n)//模拟环
                index= 0;
            if(v[index]==false)
                ++step;
            if(step==m)
            {
                v[index] =true;
                step=0;
                count++;
            }
        }
        return  index ;
    }
};