/*
给定一个正数n 可以将其分割成多个数字的和，若要让这些数字的乘积最大，求分割的方法（至少要分成两个数），算法返回这个最大的乘积。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    int max3( int a , int b , int c ){
        return max(max(a,b),c);
    }
public:
    int integerBreak(int n) {

        vector<int> memo(n+1, -1);

        memo[1] = 1;
        for( int i = 2 ; i <= n ; i ++ )
            for( int j = 1 ; j <= i-1 ; j ++ )
                memo[i] = max3( memo[i] , j*(i-j) , j*memo[i-j]);
        return memo[n];
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(3)<<endl;
    cout<<Solution().integerBreak(4)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}

**************************************************************************************
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int breakInteger( int n ){

        if( memo[n] != -1 )
            return memo[n];

        int res = n;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n) {

        memo = vector<int>(n+1, -1);
        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        return res;
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}

*********************************************************************************
#include <iostream>

using namespace std;

class Solution {
private:
    int breakInteger( int n ){

        int res = n;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        return res;
    }
public:
    int integerBreak(int n) {

        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max( res , i * breakInteger(n-i) );
        return res;
    }
};

int main() {

    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}
