/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

 

这道求岛屿数量的题的本质是求矩阵中连续区域的个数，很容易想到需要用深度优先搜索DFS来解，我们需要建立一个visited数组用来记录某个位置是否被访问过，对于
一个为‘1’且未被访问过的位置，我们递归进入其上下左右位置上为‘1’的数，将其visited对应值赋为true，继续进入其所有相连的邻位置，这样可以将这个连通区域
所有的数找出来，并将其对应的visited中的值赋true，找完次区域后，我们将结果res自增1，然后我们在继续找下一个为‘1’且未被访问过的位置，以此类推直至遍
历完整个原数组即可得到最终结果，代码如下：
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从grid[x][y]的位置开始,进行floodfill
    // 保证(x,y)合法,且grid[x][y]是没有被访问过的陆地
    void dfs( vector<vector<char>>& grid , int x , int y ){

        //assert( inArea(x,y) );
        visited[x][y] = true;
        for( int i = 0 ; i < 4 ; i ++ ){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if( inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1' )
                dfs( grid , newx , newy );
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if( m == 0 )
            return 0;
        n = grid[0].size();
        visited = vector<vector<bool> >(m,vector<bool>(n,false));

        int res = 0;
        for( int i = 0 ; i < m ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                if( grid[i][j] == '1' && !visited[i][j] ){
                    dfs( grid , i , j );
                    res ++;
                }
        return res;
    }
};

int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}};
    vector<vector<char>> grid1;
    for(int i = 0 ; i < 4 ; i ++ )
        grid1.push_back( vector<char>( g1[i] , g1[i] + sizeof( g1[i])/sizeof(char) ) );
    cout<<Solution().numIslands(grid1)<<endl;

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}};
    vector<vector<char>> grid2;
    for(int i = 0 ; i < 4 ; i ++ )
        grid2.push_back( vector<char>( g2[i] , g2[i] + sizeof( g2[i])/sizeof(char) ) );
    cout<<Solution().numIslands(grid2)<<endl;

    return 0;
}
