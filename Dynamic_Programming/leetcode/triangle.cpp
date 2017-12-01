/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
 

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 

这道题和Dungeon Game 地牢游戏非常的类似，都是用动态规划Dynamic Programming来求解的问题。而且递推式也比较容易看出来，我最先想到的方法是:

从第二行开始，triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]), 然后两边的数字直接赋值上一行的边界值，由于限制了空间复杂度，所以
我干脆直接就更新triangle数组，代码如下：
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1) triangle[i][j] += triangle[i - 1][j - 1];
                else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        int res = triangle[n - 1][0];
        for (int i = 0; i < triangle[n - 1].size(); ++i) {
            res = min(res, triangle[n - 1][i]);
        }
        return res;
    }
};

/*
这种方法可以通过OJ，但是毕竟修改了原始数组triangle，并不是很理想的方法。在网上搜到一种更好的DP方法，这种方法复制了三角形最后一行，作为用来更新的一
位数组。然后逐个遍历这个DP数组，对于每个数字，和它之后的元素比较选择较小的再加上上面一行相邻位置的元素做为新的元素，然后一层一层的向上扫描，整个过程
和冒泡排序的原理差不多，最后最小的元素都冒到前面，第一个元素即为所求。代码如下：
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
