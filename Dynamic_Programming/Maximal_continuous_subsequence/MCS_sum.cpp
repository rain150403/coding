//转自：http://blog.csdn.net/hcbbt/article/details/10454947  真是总结的太详细了，一定要好好学习！

/*

问题描述：
      连续子序列最大和，其实就是求一个序列中连续的子序列中元素和最大的那个。
      比如例如给定序列：
           { -2, 11, -4, 13, -5, -2 }
        其最大连续子序列为{ 11, -4, 13 }，最大和为20。
===============================================================


问题分析：
1.首先最朴素的方法是暴力 O(n^3)
       直接两个for循环枚举子序列的首尾，然后再来个循环计算序列的和，每次更新和的最大值。
        但是这种方法的复杂度是O(n^3)，效率实在太低了。。。
————————————————————————————————————————————————
2.第二种方法是预处理 O(n^2)
       在读入的时候将前面数的和放在数组中，就能得到一个数组sum[i]储存前i个数的和。然后两重循环枚举首尾，利用sum数组迅速求出子序列的和。
        其实这种方法只是优化了前面那种方法的计算和的循环，复杂的是O(n^2)，也很糟糕。
————————————————————————————————————————————————
3.第三种是利用分治思想 O(nlogn)
      分治算法但看代码不是很好理解，其实思想很简单，就是把序列分成两块计算，用递归分别求出两块序列中的最大子序列和，然后从序列中间向两边遍历求出包含中心的序列的最大和。返回最大的那个序列和。
       递归真的很神奇，一直把问题分解乘小问题交给下一层递归处理，直到最底层。
       用分治算法的复杂度好了一些，是O(nlogn)，虽然不是最优解，但是理解这种算法的确能让我们对递归理解得更加深刻。
————————————————————————————————————————————————
4.第四种是累积遍历算法 O(n)
      遍历序列的时候对Sum进行累计，如果Sum累积后小于0的话就把Sum重置为负无穷，每次更新Sum的最大值。最后便能求出最大值。
       其实这个算法就是把序列分为好几块，每一块满足：对于任意k，前k个数的和不会小于0（小于0就会分裂成两块了），当前i个数的和大于最大值时就进行更新，而最大值的左边界就是该块序列的第一个，右边界是第i个。
       时间复杂度为O(n)，而且可以一边读取一边处理，不需要开辟数组来存，空间也很省。
------------------------------------------------------------------------------
   举个例子: 
-10   1  2  3  4  -5   -23   3  7    -21   (num)
-10 | 1  3  6 10  8 | -23 |  3 10 | -21   (Sum)（|号为该处Sum被清零）
   由于10是Sum的最大值，所以，红色的那块就是要求的范围了。
------------------------------------------------------------------------------
     但是为什么所求序列为什么是在序列块中并且是以序列块第一个数作为开头呢？
证明：如果不是这样的话，会有几种情况：
          1  该目标序列跨越了几个块。由于Sum在<=0的时候会重置为负无穷，如果跨块的话，没有重置那它的和肯定不会是最大的。
          2  该目标序列在序列块中间，且目标序列的开头并不是序列的第一个。由于序列块前k个数的和不会小于0，所以这样肯定没有从第一个开始来的大。
————————————————————————————————————————————————
5.第五种是动态规划 O(n)
        dp做法是很普遍的做法，只要想出状态转移方程就可以很快做出来了。
        状态转移方程：sum[i] = max{sum[i-1]+a[i],a[i]}. (sum[i]记录以a[i]为子序列末端的最大连续和。)在dp的过程中便可以更新sum数组的最大值以及两个边界。
        其实完全可以不用开数组，累计sum直到sum + a < a，把sum赋值为a，更新最大值就行了。你会发现这跟第4种方法是一样的。。。只是判断条件不一样，一个是sum <= 0一个是sum + a < a。。。（其实是一样的。。。）所以复杂度和第四种是一样的都是O(n)。

————————————————————————————————————————————————
6.第六种是第二种累计求和 O(n)
       （感谢@shuangde800 大神的指导）
         这种方法跟第4种一样是累计求和。我们可以发现，连续子序列的和其实就是 （到尾端的和）-（到首端-1的和），要让这个式子最大其实可以让（到首端-1的和）尽量的小，我们可以遍历数组，维护（到首端-1的和）的最小值。
         理解起来就是遍历的时候，找出以当前位置为尾端，以此前的某一点为首端的 和最大的子序列，然后更新最大值。（其实这个思想和第五种方法是异曲同工的）
         由于只需要一遍遍历，所以复杂度为O(n)。
===========================================================

*/

//伪代码:
//1.暴力 O(n^3)：

max←(-∞)  
for i←1 to len do  
    for j←i to len do  
        sum←0  
        // 求和  
        for k←i to j  
            sum←sum+arr[i]  
        end for  
        // 更新最大值  
        if sum>max then  
            max←sum  
        end if  
    end for  
end for  
return max  
//===========================================================

//2.预处理 O(n^2)：

// 记录前i项和  
sum[0]←0  
for i←1 to len do  
    sum[i]←sum[i-1]+arr[i]  
end for  
// 枚举首尾  
max←(-∞)  
for i←1 to len do  
    for j←i to len do  
        // 更新最大值  
        if sum[j]-sum[i-1]>max then  
            max←sum[j]-sum[i-1]  
        end if  
    end for  
end for  
return max  
//===========================================================

//3.分治算法 O(nlogn)

function maxsum(arr,left,right)  
    // 只有一个元素就返回  
    if right-left=1 then  
        return  
    end if  
    // 划分[left,mid)和[mid,left)分治  
    mid←x+(y-x)/2  
    L←maxsum(arr,left,mid)  
    R←maxsum(arr,mid,left)  
    if L>R then  
        max←L  
    else  
        max←R  
    end if  
    // 求出处于中间的连续子序列最大和  
    // 先求从中间向左最大值  
    tempSum←0  
    leftSum←arr[m-1]  
    for i←m-1 downto right do  
        tempSum←tempSum+arr[i]  
        if leftSum<tempSum then  
            leftSum←tempSum  
        end if  
    end for  
    // 再求从中间向右最大值  
    tempSum←0  
    rightSum←arr[m]  
    for i←m to left do  
        tempSum←tempSum+arr[i]  
        if rightSum<tempSum then  
            rightSum←tempSum  
        end if  
    end for  
    midSum←leftSum+rightSum  
    if max<midSum then  
        max←midSum  
    end if  
    return max  
end function  
//===========================================================

//4.累积遍历算法 O(n)

sum←0  
max←arr[0]  
for i←1 to len do  
    if sum<=0 then  
        sum←a[i]  
    end if  
    if max<sum then  
        max←sum  
    end if  
end for  
return max 
//===========================================================

//5.动态规划 O(n)

sum←(-∞)  
max←(-∞)  
for i←1 to len do  
    if sum+arr[i]<arr[i] then  
        sum←arr[i]  
    else  
        sum←sum+arr[i]  
    end if  
    if max<sum then  
        max←sum  
    end if  
end for  
return max  
//===========================================================

//6.第二种累计求和 O(n)

max←-INF  
recMin←0  
  
for i←1 to len do  
    sum←sum+arr[i]  
    temp←sum-recMin  
    // 更新max  
    if temp>max then  
        max←temp  
    end if  
    // 更新recMin  
    if recMin>sum then  
        recMin←sum  
    end if  
end for 
//===========================================================

********************************************************************

//Solution:

//1.累积遍历算法（会TLE）

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
   
const int MAXN = 100100;  
int k, a[MAXN];  
  
int main() {  
    int n;  
    scanf("%d", &n);  
    rep(cas, n) {  
        scanf("%d", &k);  
        rep(i, k) scanf("%d", &a[i]);  
        int res = a[0], rl = 0, rr = 0;  
        int sum = 0, l = 0;  
        rep(i, k) {  
            if (sum < 0) {  
                sum = a[i];  
                l = i;  
            }  
            else  
                sum += a[i];  
            if (res < sum) res = sum, rl = l, rr = i;  
        }  
        if (cas) printf("\n");  
        printf("Case %d:\n", cas + 1);  
        printf("%d %d %d\n", res, rl + 1, rr + 1);  
    }  
    return 0;  
}  
//===========================================================

//2.动态规划

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
  
int main() {  
    int l, R, L, Max, sum, k, t, cas, n;  
    scanf("%d", &n);  
    rep(cas, n) {  
        sum = Max = -0xfffffff;  
        scanf("%d", &k);  
        rep (i, k) {  
            scanf("%d", &t);  
            if (sum + t < t) sum = t, l = i;  
            else sum += t;  
            if (Max < sum) Max = sum, L = l, R = i;  
        }  
        if (cas) printf("\n");  
        printf("Case %d:\n", cas + 1);  
        printf("%d %d %d\n", Max, L + 1, R + 1);  
    }  
    return 0;  
}  
//===========================================================

//3.第二种累计求和

#include <cstdio>  
int n, a[1000000];  
int max, recMin, sum, l, recL, recR;  
  
int main() {  
    int k;  
    scanf("%d", &k);  
    for (int cas = 1; cas <= k; cas++) {  
        scanf("%d", &n);  
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);  
        max = -0xfffffff;  
        sum = 0;  
        recMin = 0;  
        l = -1;  
        recL = -1, recR = 0;  
        for (int i = 0; i < n; i++) {  
            sum += a[i];  
            if (sum - recMin > max) {  
                max = sum - recMin;  
                recL = l;  
                recR = i;  
            }  
            if (recMin > sum) {  
                recMin = sum;  
                l = i;  
            }  
        }  
        if (cas - 1) printf("\n");  
        printf("Case %d:\n%d %d %d\n", cas, max, recL + 2, recR + 1);  
    }  
    return 0;  
}  
//===========================================================

//1.预处理

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
#define repf(i, a, b) for (int i = (a); i <= (b); i++)  
  
const int MAXN = 10010;  
int k, s[MAXN], a[MAXN];  
  
int main() {  
    while (scanf("%d", &k) && k) {  
        s[0] = 0;  
        repf(i, 1, k) {  
            scanf("%d", &a[i]);  
            s[i] = s[i - 1] + a[i];  
        }  
        int ans, l, r;  
        ans = l = r = s[1];  
        repf(i, 1, k) repf(j, i, k)  
            if (ans < s[j] - s[i - 1]) {  
                ans = s[j] - s[i - 1];  
                l = a[i];  
                r = a[j];  
            }  
        if (ans >= 0)  
            printf("%d %d %d\n", ans, l, r);  
        else  
            printf("0 %d %d\n", a[1], a[k]);  
    }  
    return 0;  
}  
//===========================================================

//2.分治思想

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
   
const int MAXN = 10010;  
struct ANS {  
    int sum;  
    int l, r;  
    ANS() {}  
    ANS(int a, int b, int c) : sum(a), l(b), r(c) {}  
};  
  
ANS maxsum(int* a, int x, int y) {  
    int m, v, L, R, l, r;  
    ANS M(a[x], a[x], a[x]), t1, t2;  
    if (y - x == 1)  
        return M;  
    m = x + (y - x) / 2;  
    t1 = maxsum(a, x, m);  
    t2 = maxsum(a, m, y);  
    if (t1.sum >= t2.sum) M = t1;  
    else M = t2;  
    v = 0; L = a[m - 1]; l = a[m - 1];  
    for (int i = m - 1; i >= x; i--){  
        v += a[i];  
        if (v > L) L = v, l = a[i];  
    }  
    v = 0; R = a[m]; r = a[m];  
    for (int i = m; i < y; i++) {  
        v += a[i];  
        if (v > R) R = v, r = a[i];  
    }  
    if (M.sum > (L + R))  
        return M;  
    return ANS(L + R, l, r);  
}  
  
int k, a[MAXN];  
int main() {  
    while (scanf("%d", &k) && k) {  
        rep(i, k) scanf("%d", &a[i]);  
        ANS ans = maxsum(a, 0, k);  
        if (ans.sum >= 0)  
            printf("%d %d %d\n", ans.sum, ans.l, ans.r);   
        else  
            printf("0 %d %d\n", a[0], a[k - 1]);  
    }  
    return 0;  
}  
//===========================================================

//3.累积遍历算法

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
   
const int MAXN = 10010;  
int k, a[MAXN];  
  
int main() {  
    while (scanf("%d", &k) && k) {  
        rep(i, k) scanf("%d", &a[i]);  
        int res = a[0], rl = a[0], rr = a[k - 1];  
        int sum = 0, l = 0;  
        rep(i, k) {  
            if (sum <= 0) {  
                sum = a[i];  
                l = a[i];  
            }  
            else  
                sum += a[i];  
            if (res < sum) res = sum, rl = l, rr = a[i];  
        }  
        if (res >= 0)  
            printf("%d %d %d\n", res, rl, rr);  
        else  
            printf("0 %d %d\n", a[0], a[k - 1]);  
    }  
    return 0;  
}  
//===========================================================

//4. 动态规划

#include <cstdio>  
#define rep(i, n) for (int i = 0; i < (n); i++)  
  
int main() {  
    int l, R, L, Max, sum, k, t;  
    while (scanf("%d", &k) && k) {  
        sum = Max = -0xfffffff;  
        rep (i, k) {  
            scanf("%d", &t);  
            if (sum + t < t) sum = t, l = t;  
            else sum += t;  
            if (Max < sum) Max = sum, L = l, R = t;  
        }  
        if (Max >= 0)  
            printf("%d %d %d\n", Max, L, R);  
        else  
            printf("0 %d %d\n", L, t);  
    }  
    return 0;  
}  
//===========================================================

//5.第二种累计求和

#include <cstdio>  
int n, a[1000000];  
int max, recMin, sum, l, recL, recR;  
  
int main() {  
    while (scanf("%d", &n) && n) {  
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);  
        max = -0xfffffff;  
        sum = 0;  
        recMin = 0;  
        l = -1;  
        recL = -1, recR = 0;  
        for (int i = 0; i < n; i++) {  
            sum += a[i];  
            if (sum - recMin > max) {  
                max = sum - recMin;  
                recL = l;  
                recR = i;  
            }  
            if (recMin > sum) {  
                recMin = sum;  
                l = i;  
            }  
        }  
        if (max >= 0)  
            printf("%d %d %d\n", max, a[recL + 1], a[recR]);  
        else  
            printf("0 %d %d\n", a[0], a[n - 1]);  
    }  
    return 0;  
}  
//===========================================================
