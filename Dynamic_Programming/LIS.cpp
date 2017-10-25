//longest increasing subsequence

/*
[编程题]最长递增子序列
时间限制：3秒空间限制：32768K

对于一个数字序列，请设计一个复杂度为O(nlogn)的算法，返回该序列的最长上升子序列的长度，这里的子序列定义为这样一个序列U1，U2...，其中Ui < Ui+1，且A[Ui] < A[Ui+1]。
给定一个数字序列A及序列的长度n，请返回最长上升子序列的长度。
测试样例：
[2,1,4,3,1,5,6],7
返回：4
*/

//方法一：牛客网

/*
典型动态规划题目。
对于arr，生成dp，dp[i]表示在必须以arr[i]这个数结尾的情况下，arr[o...i]中的最大递增子序列长度。

dp[0]=1
对于dp[i],所有比arr[i]小的数都可以作为倒数第2个数，其中，哪个数的dp最大，则将其作为倒数第2个数
dp[i]=max{dp[j]+1 (0<=j<1,arr[j]<arr[i])}
返回dp中最大的数
*/

class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        vector<int> dp(n,0);
        int res=0;
        dp[0]=1;
        for(int i=0;i!=n;i++){
            int max=0,j=0;
            while(j<i){
                if(A[j]<A[i]&&dp[j]>max)
                    max=dp[j];
                j++;
            }
            dp[i]=max+1;
        }
        for(int i=0;i!=n;i++)
            if(res<dp[i])
                res=dp[i];
        return res;
    }
};

//方法二：慕课网（思想同上）
class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {

        if( nums.size() == 0 )
            return 0;

        vector<int >memo( nums.size() , 1 );
        for( int i = 1 ; i < nums.size() ; i ++ )
            for( int j = 0 ; j < i ; j ++ )
                if( nums[i] > nums[j] )
                    memo[i] = max( memo[i] , 1 + memo[j] );

        int res = memo[0];
        for( int i = 1 ; i < nums.size() ; i ++ )
            res = max( res , memo[i] );

        return res;
    }
};
*******************************************************
class Solution {

private:
    vector<int> memo;

    int getMaxLength(const vector<int> &nums, int index){

        if( memo[index] != -1 )
            return memo[index];

        int res = 1;
        for( int i = 0 ; i <= index-1 ; i ++ )
            if( nums[index] > nums[i] )
                res = max( res , 1 + getMaxLength(nums,i) );

        memo[index] = res;
        return res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        if( nums.size() == 0 )
            return 0;

        memo = vector<int>( nums.size() , -1 );
        int res = 1;
        for( int i = 0 ; i < nums.size() ; i ++ )
            res = max(res, getMaxLength(nums, i));

        return res;
    }
};
