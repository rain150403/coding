/*
滑动窗口， 双索引技术two pointer

给定一个整形数组和一个数字s，找到数组中最短的一个连续子数组，使得sum >= s，返回subarray长度。

给l和r一个起始，在l， r 之间搜索求和
*/

//方法三：滑动窗口，加上最后一个数，或者减去第一个数
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 滑动窗口的思路
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int l = 0 , r = -1; // nums[l...r]为我们的滑动窗口
        int sum = 0;
        int res = nums.size()+1;

        while( l < nums.size() ){   // 窗口的左边界在数组范围内,则循环继续

            if( r + 1 < nums.size() && sum < s )
                sum += nums[++r];
            else // r已经到头 或者 sum >= s
                sum -= nums[l++];

            if( sum >= s )
                res = min(res, r-l+1);
        }

        if( res == nums.size() + 1 )
            return 0;
        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}

//方法二：把计算结果存起来，避免重复计算
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 优化暴力解
// 时间复杂度: O(n^2)
// 空间复杂度: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        // sums[i]存放nums[0...i-1]的和
        vector<int> sums(nums.size()+1,0);
        for( int i = 1 ; i <= nums.size() ; i ++ )
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.size() + 1;
        for( int l = 0 ; l < nums.size() ; l ++ )
            for( int r = l ; r < nums.size() ; r ++ ){
                // 使用sums[r+1] - sums[l] 快速获得nums[l...r]的和
                if( sums[r+1] - sums[l] >= s )
                    res = min( res , r - l + 1 );
            }

        if( res == nums.size() + 1 )
            return 0;

        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}

//方法一：暴力解法
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 暴力解法
// 时间复杂度: O(n^3)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int res = nums.size() + 1;
        for( int l = 0 ; l < nums.size() ; l ++ )
            for( int r = l ; r < nums.size() ; r ++ ){
                int sum = 0;
                for( int i = l ; i <= r ; i ++ )
                    sum += nums[i];
                if( sum >= s )
                    res = min( res , r - l + 1 );
            }

        if( res == nums.size() + 1 )
            return 0;

        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}

//方法四：滑动窗口的另一个实现，仅供参考
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 另外一个滑动窗口的实现, 仅供参考
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        assert( s > 0 );

        int l = 0 , r = -1; // [l...r]为我们的窗口
        int sum = 0;
        int res = nums.size()+1;

        while( r + 1 < nums.size() ){   // 窗口的右边界无法继续扩展了, 则循环继续

            while( r + 1 < nums.size() && sum < s )
                sum += nums[++r];

            if( sum >= s )
                res = min(res, r-l+1);

            while( l < nums.size() && sum >= s ){
                sum -= nums[l++];
                if( sum >= s )
                    res = min(res, r-l+1);
            }
        }

        if( res == nums.size() + 1 )
            return 0;
        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int) );
    int s = 7;

    cout<<Solution().minSubArrayLen(s, vec)<<endl;

    return 0;
}
