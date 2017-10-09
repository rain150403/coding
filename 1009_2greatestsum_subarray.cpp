/*
时间限制：1秒 空间限制：32768K 
本题知识点： 数组

题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*/

//运行时间：2ms 占用内存：496K

class Solution {
public:
    bool g_InvalidInput = false;
    
    int FindGreatestSumOfSubArray(vector<int> array) {
        
        int nLength = array.size();
        
        if( array.empty() || nLength <= 0 ){
            g_InvalidInput = true;
            return 0;
        }
        
        g_InvalidInput = false;
        
        int nCurSum = 0;
        int nGreatestSum = 0x80000000;
        for( int i = 0; i < nLength; ++i ){
            if( nCurSum <= 0 )
                nCurSum = array[i];
            else
                nCurSum += array[i];
            
            if( nCurSum > nGreatestSum )
                nGreatestSum = nCurSum;
        }
        return nGreatestSum;
    }
};
