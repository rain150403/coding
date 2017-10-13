/*
时间限制：1秒 空间限制：32768K 

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

//运行时间：0ms 占用内存：496k

//书上给了template的实现，这里发现去掉也没什么问题
//基于STL中的函数push_heap, pop_heap,以及vector实现堆，用less，greater分别来实现最大堆和最小堆。


/*
解释：
1.首先要保证数据平均分配到两个堆中，因此两个堆中数据的数目之差不能超过1.为了实现平均分配，可以在数据的总数目是偶数时把新数据插入到最小堆中，
否则插入到最大堆中。

2.还要保证最大堆中的所有数据都要小于最小堆中的数据。
当数据的总数目是偶数，但是新的数据比最大堆中的一些数据要小时，
先插入到最大堆中，接着把最大堆的最大数字拿出来插入到最小堆中。

当数据的总数目是奇数，但是新的数据比最小堆中的一些数据要大时，
先插入最小堆，接着把最小堆的最小数字拿出来插入到最大堆中。
*/

class Solution {
private:
    vector<int> min;
    vector<int> max;

public:
    void Insert(int num)
    {
	int size = min.size() + max.size();
        if( ( size & 1 ) == 0 ){
            if( max.size() > 0 && num < max[0] ){
                max.push_back(num);
                push_heap( max.begin(), max.end(), less<int>() );
                
                num = max[0];
                
                pop_heap( max.begin(), max.end(), less<int>() );
                max.pop_back();
            }
            
            min.push_back(num);
            push_heap( min.begin(), min.end(), greater<int>() );
        }
        else{
            if( min.size() > 0 && min[0] < num ){
                min.push_back(num);
                push_heap( min.begin(), min.end(), greater<int>() );
                
                num = min[0];
                
                pop_heap(min.begin(), min.end(), greater<int>() );
                min.pop_back();
            }
            
            max.push_back( num );
            push_heap( max.begin(), max.end(), less<int>() );
        }
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
        
        if( size <= 0 )
            return 0;
        
        double median = 0;
        if( ( size & 1 ) == 0 ) //奇偶数判断
	          median = ( min[0] + max[0] ) / 2.0;            
        else 
            median = min[0];
        
        return median;
    }
};

