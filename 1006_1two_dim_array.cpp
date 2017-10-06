/*
时间限制：1秒 空间限制：32768K
本题知识点： 查找

题目描述:
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

*/

//运行时间：8ms，占用内存：1400K

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool found = false;
        int rows = array.size();
        int columns = array[0].size();
        if( !array.empty() && rows > 0 && columns > 0 ){
            int row = 0;
            int column = columns - 1;
            while( row < rows && column >= 0 ){
                if(array[row][column] == target){
                    found = true;
                    break;
                }else if(array[row][column] > target)
                    --column;
                else
                    ++row;
            }
        }
        return found;
    }
};
