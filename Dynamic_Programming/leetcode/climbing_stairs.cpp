/*
有一个楼梯，总共有n阶台阶，每一次可以上一个台阶，也可以上两个台阶，问：爬上这样的一个楼梯，一共有多少种不同的方法？
*/

#include <iostream>
#include <vector>

using namespace std;

// 记忆化搜索
class Solution {
private:
    vector<int> memo;

    int calcWays(int n){

        if( n == 0 || n == 1)
            return 1;

        if( memo[n] == -1 )
            memo[n] = calcWays(n-1) + calcWays(n-2);

        return memo[n];
    }
public:
    int climbStairs(int n) {

        memo = vector<int>(n+1,-1);
        return calcWays(n);
    }
};

int main() {

    cout<<Solution().climbStairs(10)<<endl;
    return 0;
}

*************************************************************************************

#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution {

public:
    int climbStairs(int n) {

        vector<int> memo(n+1,-1);
        memo[0] = 1;
        memo[1] = 1;
        for( int i = 2 ; i <= n ; i ++ )
            memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};

int main() {

    cout<<Solution().climbStairs(10)<<endl;
    return 0;
}
