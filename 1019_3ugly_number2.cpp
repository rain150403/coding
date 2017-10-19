/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个
丑数。
*/

//运行时间：3ms 占用内存：500k

class Solution {
public:
    int Min( int number1, int number2, int number3 ){
        int min = ( number1 < number2 ) ? number1 : number2;
        min = ( min < number3 ) ? min : number3;
        
        return min;
    }
    
    int GetUglyNumber_Solution(int index) {
        if( index <= 0 )
            return 0;
        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        
        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;
        
        while( nextUglyIndex < index ){
            int min = Min( *pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5 );
            pUglyNumbers[nextUglyIndex] = min;
            
            while( *pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex] )
                ++pMultiply2;
            while( *pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex] )
                ++pMultiply3;
            while( *pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex] )
                ++pMultiply5;
            
            ++nextUglyIndex;
        }
        
        int ugly = pUglyNumbers[nextUglyIndex - 1];
        delete[] pUglyNumbers;
        return ugly;
    }
};
