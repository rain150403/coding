/*
时间限制：1秒 空间限制：32768K

题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于
k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？
*/

//知识点：回溯法

//运行时间：1ms, 占用内存：496K

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited = new bool[rows * cols];
        for( int i = 0; i < rows * cols; ++i )
            visited[i] = false;
        
        int count = movingCountCore( threshold, rows, cols, 0, 0, visited );
        
        delete[] visited;
        
        return count;
    }
    
    int movingCountCore( int threshold, int rows, int cols, int row, int col, bool* visited ){
        int count = 0;
        if( check( threshold, rows, cols, row, col, visited ) ){
            visited[ row * cols + col ] = true;
            
            count = 1 + movingCountCore( threshold, rows, cols, row - 1, col, visited )
                + movingCountCore( threshold, rows, cols, row, col - 1, visited )
                + movingCountCore( threshold, rows, cols, row + 1, col, visited )
                + movingCountCore( threshold, rows, cols, row, col + 1, visited );
        }
        
        return count;
    }
    
    bool check( int threshold, int rows, int cols, int row, int col, bool* visited ){
        if( row >= 0 && row < rows && col >= 0 && col < cols 
          && getDigitSum(row) + getDigitSum(col) <= threshold
          && !visited[row * cols + col] )
            return true;
        
        return false;
    }
    
    int getDigitSum( int number ){
        int sum = 0;
        while( number > 0 ){
            sum += number % 10;
            number /= 10;
        }
        
        return sum;
    }
};
