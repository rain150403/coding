/*
分析：若暴力求解，须要O(n^3)时间，太低效，故使用动态规划。
设data[i]：第i个数据，dp[i]:以第i个数结尾的连续子序列最大乘积，
若题目要求的是最大连续子序列和，则易确定状态转移方程为：
dp[i]=max(data[i]，dp[i-1]+data[i])(dp[i]为以第i个数结尾的连续子序列最大和)
但乘积存在负负得正的问题，即原本非常小的负数成了一个负数反而变大了。（负数逆袭了），

故不能照抄加法的转移方程，为了解决问题。须要定义两个数组：

dp1[i]:以第i个数结尾的连续子序列最大乘积
dp2[i]:以第i个数结尾的连续子序列最小乘积
转移方程:
dp1[i]=max(data[i],dp1[i-1]*data[i],dp2[i-1]*data[i]);
dp2[i]=min(data[i],dp1[i-1]*data[i],dp2[i-1]*data[i]);

最后遍历dp1得到最大值即为答案。
*/

#include <stdio.h>  
   
#define LEN 100000  
   
int N;  
double data[LEN];  
double max[LEN];  
double min[LEN];  
   
double Max(double a, double b){  
    return (a > b) ? a : b;  
}  
   
double Min(double a, double b){  
    return (a < b) ? a : b;  
}  
   
double MMS(){  
    int i;  
    double ans;  
    max[0] = min[0] = data[0];  
    ans = data[0];  
    for (i = 1; i < N; ++i){  
        max[i] = Max(Max(data[i], max[i-1]*data[i]), min[i-1]*data[i]);  
        min[i] = Min(Min(data[i], max[i-1]*data[i]), min[i-1]*data[i]);  
        ans = Max(ans, max[i]);  
    }  
    return ans;  
}  
   
int main(void){  
    int i;  
    double ans;  
    while (scanf("%d", &N) != EOF){  
        for (i = 0; i < N; ++i)  
            scanf("%lf", &data[i]);  
        ans = MMS();  
        if (ans < 0)  
            printf("-1\n");  
        else if (ans - (int)ans <= 1e-5)  
            printf("%lld\n", (int)ans);  
        else  
            printf("%.2lf\n", ans);  
    }  
   
    return 0;  
}  
