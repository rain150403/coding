//递归方法

#include <iostream>
#include <ctime>

using namespace std;

int fib( int n ){

    if( n == 0 )
        return 0;

    if( n == 1 )
        return 1;

    return fib(n-1) + fib(n-2);
}

int main() {

    int n = 42;
    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();
    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    return 0;
}

//记忆化搜索

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

vector<int> memo;

// 记忆化搜索
int fib( int n ){

    if( n == 0 )
        return 0;

    if( n == 1 )
        return 1;

    if( memo[n] == -1 )
        memo[n] = fib(n-1) + fib(n-2);

    return memo[n];
}

int main() {

    int n = 1000;
    memo = vector<int>(n+1,-1);

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    return 0;
}

//动态规划

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// 动态规划
int fib( int n ){

    vector<int> memo(n+1, -1);

    memo[0] = 0;
    memo[1] = 1;
    for( int i = 2 ; i <= n ; i ++ )
        memo[i] = memo[i-1] + memo[i-2];

    return memo[n];
}

int main() {

    int n = 1000;

    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();

    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    return 0;
}
