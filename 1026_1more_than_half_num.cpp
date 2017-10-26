/*
时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度
的一半，因此输出2。如果不存在则输出0。
*/

//运行时间：1ms 占用内存：496k

class Solution {
public:
    bool g_bInputInvalid = false;
    
    bool CheckInvalidArray( vector<int> numbers, int length ){
        g_bInputInvalid = false;
        if( length <= 0 )
            g_bInputInvalid = true;
        
        return g_bInputInvalid;
    }
    
    bool CheckMoreThanHalf( vector<int> numbers, int length, int number ){
        int times = 0;
        for( int i = 0; i < length; ++i ){
            if( numbers[i] == number )
                times++;
        }
        
        bool isMoreThanHalf = true;
        if( times * 2 <= length ){
            g_bInputInvalid = true;
            isMoreThanHalf = false;
        }
        
        return isMoreThanHalf;
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        
        if( CheckInvalidArray( numbers, length ) )
            return 0;
        
        int result = numbers[0];
        int times = 1;
        for( int i = 1; i < length; ++i ){
            if( times == 0 ){
                result = numbers[i];
                times = 1;
            }
            else if( numbers[i] == result )
                times++;
            else 
                times--;
        }
        if( !CheckMoreThanHalf( numbers, length, result ) )
            result = 0;
        return result;
    }
};
