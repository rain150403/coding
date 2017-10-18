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
