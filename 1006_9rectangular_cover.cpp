/*
时间限制：1秒 空间限制：32768K

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

//运行时间：3ms，占用内存：496K

class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) {
            return number;
        }
        int f1 = 1;
        int f2 = 2;
        int f3;
         
        for (int i = 3; i <= number; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
