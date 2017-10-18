/*
时间限制：1秒 空间限制：32768K
本题知识点： 排序 链表 leetcode

题目描述

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time 
complexity should be O(log (m+n)).
*/

//运行时间：21ms 占用内存：496k

/*
//合并数组，然后快速确定中间值
/*解题思路：
（1）第一步将两个有序数组合并成一个有序的数组（或者向量）（类似于两个有序链表的合并）
（2）得到最终的数组（或者向量）长度为m+n，然后判断是有奇数个值，还是有偶数个值
（3）如果有奇数个值，那么只有一个中间值，对应的编号为 （数组（或者向量）长度 -1）/2，取出值，直接返回
（4）如果有偶数个值，那么有两个中间值，对应编号为：
    1）数组（或者向量）长度 /2 2）数组（或者向量）长度 /2 - 1
（5）取出对应的值，然后求平均，得到最终结果 */
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m+n) / 2 + 1;
        int i, j;
        vector<int> vec;
        for( i = 0, j = 0; i < m && j < n; ){
            if( A[i] > B[j] )
                vec.push_back( B[j++] );
            else
                vec.push_back( A[i++] );
            if( vec.size() == mid )
                break;
        }
        
        while( vec.size() != mid ){
            if( i < m )
                vec.push_back( A[i++] );
            if( j < n )
                vec.push_back( B[j++] );
        }
        
        if( (m+n) % 2 == 0 )
            return ( vec[vec.size() - 1] + vec[vec.size() - 2] ) / 2.0;
        return *( vec.end() - 1 );
    }
};
