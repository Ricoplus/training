#include<stdio.h>
#include<iostream>
using namespace std;

// 题目描述
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，
//向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
//路径不能再次进入该格子。
class Solution {
public:
    bool Judge(char* matrix,int rows,int cols,int x,int y,char* str,int count,bool* flag)
    {
        if(x>=0&&x<rows
           &&y>=0&&y<cols
           &&matrix[x*cols+y]==str[count]
           &&flag[y+x*cols]==false)
            return true;
        return false;
    }
    bool _hasPath(char* matrix,int rows,int cols,int x,int y,char* str,int count,bool* flag)
    {
        if(str[count]=='\0')
            return true;
        if(Judge(matrix,rows,cols,x,y,str,count,flag))
        {
            ++count;
            flag[y+x*cols] = true;
            bool sign = _hasPath(matrix,rows,cols,x+1,y,str,count,flag)||_hasPath(matrix,rows,cols,x-1,y,str,count,flag)
                        ||_hasPath(matrix,rows,cols,x,y-1,str,count,flag)||_hasPath(matrix,rows,cols,x,y+1,str,count,flag);
            flag[y+x*cols] = false; 
            return sign;
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||str==NULL||rows<=0||cols<=0)
            return false;
        int count = 0;
        bool* flag = new bool[rows*cols];
        for(int i = 0 ;i<rows*cols;i++)
        {
            flag[i]=false;
        }
        for(int i = 0 ;i<rows;i++)
        {
            for(int j = 0 ;j<cols;j++)
            {
                if(_hasPath(matrix,rows,cols,i,j,str,count,flag))
                    return true;
            }
        }
        return false;
    }
};