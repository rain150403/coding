/*
时间限制：1秒 空间限制：32768K

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

//运行时间：2ms  占用内存：512k

//开始还在纠结乘积最小，后来转念一想，a+b=sum,a和b越远乘积越小，而一头一尾两个指针往内靠近的方法找到的就是乘积最
//小的情况。如果是乘积最大的情况就是一直找到两个指针重合，每次找到一个就将之前返回的结果向量清空然后更新为新找到的。
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int length = array.size();
        int start = 0;
        int end = length - 1;
        while (start < end){
            if (array[start] + array[end] == sum){
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }
            else if (array[start] + array[end] < sum)
                start++;
            else
                end--;
        }
        return result;
    }
};
