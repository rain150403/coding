/*
时间限制：1秒 空间限制：32768K 
本题知识点： 数组

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

*/

//运行时间：1ms， 占用内存：504K

class Solution {
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.empty())
            return ;
        vector<int> odd;
        vector<int> even;
 
        for(int i = 0; i < array.size();++i)
        {
            if(array[i] & 0x01)
                odd.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        int k = 0;
        for(int i = 0; i < odd.size();++i)
            array[k++] = odd[i];
        for(int i = 0; i < even.size();++i)
            array[k++] = even[i];
        return ;
    }
};
