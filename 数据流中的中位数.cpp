#include<iostream>
#include<queue>

using namespace std;
// 题目描述
// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
// 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

class Solution{
public:
    vector<double> v;
    void Insert(int num)
    {   
        ++count;
        if(count%2==0){
            big_heap.push(num);
            small_heap.push(big_heap.top());
            big_heap.pop();
        }else{
            small_heap.push(num);
            big_heap.push(small_heap.top());
            small_heap.pop();            
        }
    }
    double GetMedian()
    {
        if(count%2==0){
            
            return (big_heap.top()+small_heap.top())/2.0;
        }
        return big_heap.top();
    }
    private:
    int count = 0;
    priority_queue<int, vector<int>, less<int>> big_heap;//前半部分
    priority_queue<int, vector<int>, greater<int>> small_heap;//后半部分

};