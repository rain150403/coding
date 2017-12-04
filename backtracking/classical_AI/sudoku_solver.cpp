/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.



A sudoku puzzle...

 



...and its solution numbers marked in red.

 

这道求解数独的题是在之前那道 Valid Sudoku 验证数独的基础上的延伸，之前那道题让我们验证给定的数组是否为数独数组，这道让我们求解数独数组，跟此题类似的
有 Permutations 全排列，Combinations 组合项， N-Queens N皇后问题等等，其中尤其是跟 N-Queens N皇后问题的解题思路及其相似，对于每个需要填数字的格子
带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回'.'，判断新加入的数字是否合法时，只需要判定当前数字是否合法，不需
要判定这个数组是否为数独数组，因为之前加进的数字都是合法的，这样可以使程序更加高效一些，具体实现如代码所示：
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        solveSudokuDFS(board, 0, 0);
    }
    bool solveSudokuDFS(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return solveSudokuDFS(board, i + 1, 0);
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; ++k) {
                board[i][j] = (char)(k + '0');
                if (isValid(board, i , j)) {
                    if (solveSudokuDFS(board, i, j + 1)) return true;
                }
                board[i][j] = '.';
            }
        } else {
            return solveSudokuDFS(board, i, j + 1);
        }
        return false;
    }
    bool isValid(vector<vector<char> > &board, int i, int j) {
        for (int col = 0; col < 9; ++col) {
            if (col != j && board[i][j] == board[i][col]) return false;
        }
        for (int row = 0; row < 9; ++row) {
            if (row != i && board[i][j] == board[row][j]) return false;
        }
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
                if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
};
