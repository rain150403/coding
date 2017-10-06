/*
时间限制：1秒 空间限制：32768K 

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/

/*
class Solution{
public:
    int Fibonacci(int n){
        if( n <= 0 )
            return 0;
        if( n == 1 )
            return 1;
        
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

不通过
您的代码已保存
运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
case通过率为0.00%
*/


//运行时间：1ms， 占用内存：504K

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0,1};
        if( n < 2 )
            return result[n];
        
        int fibNMinusOne = 1;
        int fibNMinusTwo = 0;
        int fibN = 0;
        for( int i = 2; i <= n; ++i ){
            fibN = fibNMinusOne + fibNMinusTwo;
            
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        
        return fibN;
    }
};
