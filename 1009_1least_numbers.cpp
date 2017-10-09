/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

//运行时间：1ms 占用内存：496K

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> v;
        if(k>input.size())
            return v;
        sort(input.begin(),input.end());
        for(int i=0;i<k;i++)
            v.push_back(input[i]);
        return v;
    }
};

