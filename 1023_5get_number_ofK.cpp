/*时间限制：1秒 空间限制：32768K
本题知识点： 数组

题目描述
统计一个数字在排序数组中出现的次数。*/

//运行时间：3ms 占用内存：500k

//方法一：
//由于数组有序，所以使用二分查找方法定位k的第一次出现位置和最后一次出现位置
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int lower = getLower(data,k);
        int upper = getUpper(data,k);
         
        return upper - lower + 1;
    }
     
    //获取k第一次出现的下标
    int getLower(vector<int> data,int k){
        int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
         
        while(start <= end){
            if(data[mid] < k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return start;
    }
    //获取k最后一次出现的下标
    int getUpper(vector<int> data,int k){
         int start = 0,end = data.size()-1;
        int mid = (start + end)/2;
         
        while(start <= end){
            if(data[mid] <= k){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
         
        return end;
    }
};

//方法二：
class Solution {
public:
int BinarySearch(vector<int> data, int low, int high, int k)
{
    while (low<=high)
    {
        int m = (high + low) / 2;
        if (data[m] == k)return m;
        else if (data[m] < k) low = m+ 1;
        else high = m - 1;
    }
    return -1;
}
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)return 0;
         int len=data.size();
        int KeyIndex=0;
         
        KeyIndex=BinarySearch(data,0,len-1,k);
       if(KeyIndex==-1) return 0;
        int sumber=1;
        int m=KeyIndex-1;
        int n=KeyIndex+1;
       
       while(m>=0&&data[m]==k)
        {
                m--;sumber++;
            }
        while(n<len&&data[n]==k)
        {
               n++; sumber++;
            }
        return sumber;
    }
};
