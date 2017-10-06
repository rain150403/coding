/*
时间限制：1秒 空间限制：32768K

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//运行时间:1ms, 占用内存：500K

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         
         while(n){
             ++count;
             n = (n-1) & n;
         }
         return count;
     }
};
