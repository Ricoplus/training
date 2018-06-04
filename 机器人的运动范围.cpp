#include<iostream>
#include<vector>
#include<string>
using namespace std;

//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
//因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？


class Solution {
public:
    int getSum(int num)
    {
        int sum  = 0;
        while(num>0)
        {
            sum += num%10;
            num=num/10;
        }
        return sum;
    }
    bool check(int num,int i,int j,int rows, int cols,vector<bool>& flag)
    {
       
        if(i>=0&&j>=0&&j<cols&&i<rows&&flag[i*cols+j]==false&&getSum(i)+getSum(j)<=num)
        {
            return true;
        }
        return false;
    }
    int _movingCount(int threshold,int i,int j, int rows, int cols, vector<bool>& flag)
    {
        int count = 0;
        if(check(threshold,i,j,rows,cols,flag))
        {
            flag[i*cols+j] = true;
            count = 1+_movingCount(threshold,i-1,j,rows,cols,flag)+
                          _movingCount(threshold,i,j-1,rows,cols,flag)+
                          _movingCount(threshold,i+1,j,rows,cols,flag)+
                          _movingCount(threshold,i,j+1,rows,cols,flag);       
        }
        return count;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0)
            return 0;
        vector<bool> flag(rows*cols,false);
        return _movingCount(threshold,0,0,rows,cols,flag);
    }
};