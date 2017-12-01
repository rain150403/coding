/*
你是一个专业的小偷，打算洗劫一条街的所有房子，每一个房子里都有不同价值的宝物。但是，如果你选择偷窃连续的两栋房子，就会触发警报，编程求出你最多可以偷窃
价值多少的宝物？
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // memo[i] 表示抢劫 nums[i...n) 所能获得的最大收益
    vector<int> memo;

    int tryRob( vector<int> &nums, int index){

        if( index >= nums.size() )
            return 0;

        if( memo[index] != -1 )
            return memo[index];

        int res = 0;
        for( int i = index ; i < nums.size() ; i ++ )
            res = max(res, nums[i] + tryRob(nums, i+2));
        memo[index] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {

        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }
};

int main() {

    return 0;
}

##################################################################################

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0 )
            return 0;

        // memo[i] 表示抢劫 nums[i...n) 所能获得的最大收益
        vector<int> memo(n, 0);
        memo[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i -- ) {
            memo[i] = memo[i+1];
            for (int j = i; j < n; j++)
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0) );
        }
        return memo[0];
    }
};

int main() {

    int nums[] = {2,1};
    vector<int> vec(nums, nums+sizeof(nums)/sizeof(int));

    cout<<Solution().rob(vec)<<endl;

    return 0;
}
