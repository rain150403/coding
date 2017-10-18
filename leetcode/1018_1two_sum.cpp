/*
时间限制：1秒 空间限制：32768K
本题知识点： 哈希 leetcode

题目描述

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*

使用一个map保存每一个不同的数字最后出现的坐标，然后从下标0处开始进行查找。
即使有重复的数字，由于map中保存的是最后一次出现的位置，那样即使由两个相同
的值构成的数对也可以被找到。m[diff] > i，这个条件使用的比较好。

*/

//运行时间：1ms 占用内存：500k

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
        vector<int> res;
        for( int i = 0; i < numbers.size(); i++ ){
            m[numbers[i]] = i;
        }
        
        for( int i = 0; i < numbers.size(); i++ ){
            const int diff = target - numbers[i];
            if( m.find( diff ) != m.end() && m[diff] > i ){
                res.push_back( i+1 );
                res.push_back( m[diff] + 1 );
                break;
            }
        }
        
        return res;
    }
};
