/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

这道题是典型的深度优先遍历DFS的应用，原二维数组就像是一个迷宫，可以上下左右四个方向行走，我们以二维数组中每一个数都作为起点和给定字符串做匹配，我们
还需要一个和原数组等大小的visited数组，是bool型的，用来记录当前位置是否已经被访问过，因为题目要求一个cell只能被访问一次。如果二维数组board的当前字符
和目标字符串word对应的字符相等，则对其上下左右四个邻字符分别调用DFS的递归函数，只要有一个返回true，那么就表示可以找到对应的字符串，否则就不能找到，
具体看代码实现如下：
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从board[startx][starty]开始, 寻找word[index...word.size())
    bool searchWord( const vector<vector<char>> &board, const string& word, int index,
                    int startx, int starty ){

        //assert( inArea(startx,starty) );
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];

        if( board[startx][starty] == word[index] ){
            visited[startx][starty] = true;
            // 从startx, starty出发,向四个方向寻
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord( board , word , index + 1 , newx , newy ) )
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        visited = vector<vector<bool> >(m,vector<bool>(n,false));
        for( int i = 0 ; i < board.size() ; i ++ )
            for( int j = 0 ; j < board[i].size() ; j ++ )
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }
};

int main() {

    char b[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board;
    for( int i = 0 ; i < 3 ; i ++ )
        board.push_back( vector<char>(b[i],b[i]+sizeof(b[i])/sizeof(char)) );

    int cases = 3;
    string words[3] = {"ABCCED" , "SEE" , "ABCB" };
    for( int i = 0 ; i < cases ; i ++ )
        if( Solution().exist(board,words[i]))
            cout<<"found "<<words[i]<<endl;
        else
            cout<<"can not found "<<words[i]<<endl;

    return 0;
}
