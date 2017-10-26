/*
时间限制：1秒 空间限制：32768K

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//运行时间：1ms 占用内存：496k

//这道题不理解！！！

//用公式是不可以的，公式里有乘法！！实现乘法可以用sizeof多维数组，两行代码就可以..大神的解法，暂时不能理解
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};


//运行时间：2ms 占用内存：500k

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};

//方法三是剑指offer上的解法

typedef int (*func)( int );

class Solution {
public:
    static int Solution1(int n ){
        return 0;
    }
    
    static int Sum_Solution(int n) {
        static func f[2] = {Solution1,Sum_Solution};
        return n+f[!!n](n-1);
    }
};


