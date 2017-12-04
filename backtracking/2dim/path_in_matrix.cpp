/*
题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如在下面的3*4的矩阵中包含一条字符串“bcced"的路径（路径中的字母用斜体表示）。但矩阵中不包含字符串”abcb"的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
a b c e
s  f c s
a d e e
  这是一个可以用回溯法解决的典型题。首先,在矩阵中任选一个格子作为路径的起点。假设矩阵中某个格子的字符为ch并且这个格子将对应于路径上的第i个字符。如果路径上的第i个字符不是ch,那么这个格子不可能处在路径上的第i个位置。如果路径上的第i个字符正好是ch,那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边界上的格子之外,其他格子都有4个相邻的格子。重复这个过程直到路径上的所有字符都在矩阵中找到相应的位置。
  由于回溯法是递归特性,路径可以被看成是一个栈。当在矩阵中定位了路径中前n个字符的位置之后,在与第n个字符对应的格子的周围都没有找到第n+1个字符，这个时候只好在路径上回到第n-1个字符,重新定位第n个字符。
  由于路径不能重复进入矩阵的格子,还需要定义和字符矩阵大小一样的布尔值矩阵,用来标识路径是否已经进入了每个格子。
 下面的代码实现了这个回溯算法：
*/

bool hasPath(char* matrix,int rows,int cols,char* str)
{
 if(matrix==NULL||rows<1||cols<1||str==NULL)
 return false;
 bool *visited=new bool[rows*cols];
 memset(visited,0,rows*cols);
 int pathlength=0;
 for(int row=0;row<rows;++row)
  {
    for(int col=0;col<cols;++col)
     {
       if(hasPathCore(matrix,rows,cols,row,col,str,pathlength,visited))
        {
          return true;
         }
       }
   }
  delete[] visited;
  return false;
}

bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int& pathlength,bool* visited)
{
 if(str[pathlength]=='\0')
 return true;
 bool hasPath=false;
 if(row>=0&&row<rows&&col>=0&&col<cols\
 &&matrix[row*cols+col]==str[pathlength]&&\
 !visited[row*cols+col])
{
 ++pathlength;
 visited[row*cols+col]=true;
 
 hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathlength,visited)||\
                hasPathCore(matrix,rows,cols,row-1,col,str,pathlength,visited)||\
                hasPathCore(matrix,rows,cols,row+1,col,str,pathlength,visited)||\
                hasPathCore(matrix,rows,cols,row,col+1,str,pathlength,visited);
if(!hasPath)
 {
 --pathlength;
 visited[row*cols+col]=false;
  }
 }
 return hasPath;
}
