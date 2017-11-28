/*
给定一个有n个元素的数组，数组中元素的取值只有0， 1， 2三种可能，为之排序
*/

//方法二：
/*
有三个指针，一个是zero窗口的结束，一个是two窗口的开始，而主要的是中间的扫描指针，记得交换。
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 时间复杂度: O(n)
// 空间复杂度: O(1)
// 对整个数组只遍历了一遍
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int zero = -1;          // [0...zero] == 0
        int two = nums.size();  // [two...n-1] == 2
        for( int i = 0 ; i < two ; ){
            if( nums[i] == 1 )
                i ++;
            else if ( nums[i] == 2 )
                swap( nums[i] , nums[--two]);
            else{ // nums[i] == 0
                assert( nums[i] == 0 );
                swap( nums[++zero] , nums[i++] );
            }
        }
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    Solution().sortColors( vec );
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}


//方法一：

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(k), k为元素的取值范围
// 对整个数组遍历了两遍
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int count[3] = {0};    // 存放0,1,2三个元素的频率
        for( int i = 0 ; i < nums.size() ; i ++ ){
            assert( nums[i] >= 0 && nums[i] <= 2 );
            count[nums[i]] ++;
        }

        int index = 0;
        for( int i = 0 ; i < count[0] ; i ++ )
            nums[index++] = 0;
        for( int i = 0 ; i < count[1] ; i ++ )
            nums[index++] = 1;
        for( int i = 0 ; i < count[2] ; i ++ )
            nums[index++] = 2;

        // 小练习: 更加自使用的计数排序
    }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    Solution().sortColors( vec );
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
