/*
两个矩阵的乘法仅当第一个矩阵A的行数和另一个矩阵B的列数相等时才能定义。如A是m×n矩阵，B是n×p矩阵，它们的乘积AB是一个m×p矩阵，它的一个元素其中 1 ≤ i ≤ m,
1 ≤ j ≤ p。
*/

//暴力解法

#include <iostream>
using namespace std;
#define A_ROWS        3
#define A_COLUMNS     2
#define B_ROWS        2
#define B_COLUMNS     3
void matrix_multiply(int A[A_ROWS][A_COLUMNS],int B[B_ROWS][B_COLUMNS],int C[A_ROWS][B_COLUMNS]);
int main()
{
    int A[A_ROWS][A_COLUMNS] = {1,0,
                                1,2,
                                1,1};
    int B[B_ROWS][B_COLUMNS] = {1,1,2,
                                2,1,2};
    int C[A_ROWS][B_COLUMNS] = {0};
    matrix_multiply(A,B,C);
    for(int i=0;i<A_ROWS;i++)
    {
        for(int j=0;j<B_COLUMNS;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
void matrix_multiply(int A[A_ROWS][A_COLUMNS],int B[B_ROWS][B_COLUMNS],int C[A_ROWS][B_COLUMNS])
{
    if(A_COLUMNS != B_ROWS)
        cout<<"error: incompatible dimensions."<<endl;
    else
    {
        int i,j,k;
        for(i=0;i<A_ROWS;i++)
            for(j=0;j<B_COLUMNS;j++)
            {
                C[i][j] = 0;
                for(k=0;k<A_COLUMNS;k++)
                    C[i][j] += A[i][k] * B[k][j]; //将A的每一行的每一列与B的每一列的每一行的乘积求和
            }
    }
}

//Strassen算法  （优化算法，待学习。。。）
