/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

这道题是之前那道 N-Queens N皇后问题 的延伸，说是延伸其实我觉得两者顺序应该颠倒一样，上一道题比这道题还要稍稍复杂一些，两者本质上没有啥区别，都是要用
回溯法Backtracking来解，如果理解了之前那道题的思路，此题只要做很小的改动即可，不再需要求出具体的皇后的摆法，只需要每次生成一种解法时，计数器加一即可，
代码如下：
*/

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, res);
        return res;
    }
    void totalNQueensDFS(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) ++res;
        else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    totalNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
