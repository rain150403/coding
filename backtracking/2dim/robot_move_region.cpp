/*
题目：地上有个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，它每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格(35,37)，因为3+5+3+7=18.但它不能进入方格(35,38)，因为3+5+3+8=19.请问该机器人能够达到多少格子？
例如我们输入的K=4，则机器人能够到达的格子数为：15。范围如上黄色区域所示。
方案：这个题目和前一个题目类似，我们采用回溯法。机器人从[0,0]格子开始移动，当它移动到下一个格子的时候，我们通过格子的数位来判断该机器人是否有权利进入，如果可以，格子数+1，我们再判断[i-1,j],[i,j-1][i+1,j],[i,j+1]这相邻的四个格子能否进入。
具体实现代码如下；
*/

#include <iostream>  
using namespace std;  
int GetdigitSum(int number)//得到位数和；  
{  
    int sum=0;  
    while(number>0)  
    {  
        sum+=number%10;  
        number/=10;  
    }  
    return sum;  
}  
bool check(int threshold,int rows,int cols,int col,int row,bool*visited)  
{  
    if(row>=0 && row<rows && col>=0 && col<cols //是否越界；  
        && GetdigitSum(row)+GetdigitSum(col)<=threshold//是否在threshold内；  
        && !visited[row*cols+col])//是否已经访问；  
        return true;  
    return false;  
}  
  
  
int MoveCountHelp(int threshold,int rows,int cols,int row,int col, bool *visited)    
{    
    int count =0;    
    if(row>=0 && col>=0 &&row<rows && col<cols   
        && !visited[row*cols+col]   
        && GetdigitSum(row)+GetdigitSum(col)<=threshold)    
    {    
        visited[row*cols+col] = true;    
        count = 1+MoveCountHelp(threshold,rows,cols,row+1,col,visited)  //down  
                 +MoveCountHelp(threshold,rows,cols,row-1,col,visited)  //up  
                 +MoveCountHelp(threshold,rows,cols,row,col+1,visited)  //right  
                 +MoveCountHelp(threshold,rows,cols,row,col-1,visited); //left  
    }    
    return count;    
}    
int MoveCount(int threshold,int rows,int cols)    
{    
    if(rows<1 || cols<1 )    
        return 0;    
    bool *visited = new bool[rows*cols];    
    memset(visited,0,rows*cols);    
    int count = MoveCountHelp(threshold,rows,cols,0,0,visited);    
    delete []visited;    
    return count;    
}    
  
  
int main()  
{  
    int result=MoveCount(4,6,6);  
    cout<<"当K等于4时，机器人能进入的格子数量为："<<result<<endl;  
    system("pause");  
    return 0;  
}  
