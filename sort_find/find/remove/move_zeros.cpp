/*
给定一个数组nums， 写一个函数，将数组中所有的0都挪到数组的末尾，而维持其它所有非零元素的相对位置。
*/

//方法四：
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)
    // 空间复杂度 O(1)
    void moveZeroes(vector<int>& nums) {

        int k = 0; // nums中, [0...k)的元素均为非0元素

        // 遍历到第i个元素后,保证[0...i]中所有非0元素
        // 都按照顺序排列在[0...k)中
        // 同时, [k...i] 为0
        for(int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                if( k != i )
                    swap( nums[k++] , nums[i] );
                else
                    k ++;
    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}

//方法三：
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)
    // 空间复杂度 O(1)
    void moveZeroes(vector<int>& nums) {

        int k = 0; // nums中, [0...k)的元素均为非0元素

        // 遍历到第i个元素后,保证[0...i]中所有非0元素
        // 都按照顺序排列在[0...k)中
        // 同时, [k...i] 为0
        for(int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                swap( nums[k++] , nums[i] );

    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}

//方法二：

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)
    // 空间复杂度 O(1)
    void moveZeroes(vector<int>& nums) {

        int k = 0; // nums中, [0...k)的元素均为非0元素

        // 遍历到第i个元素后,保证[0...i]中所有非0元素
        // 都按照顺序排列在[0...k)中
        for(int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                nums[k++] = nums[i];

        // 将nums剩余的位置放置为0
        for( int i = k ; i < nums.size() ; i ++ )
            nums[i] = 0;
    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}

//方法一：

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(n)
    // 空间复杂度 O(n)
    void moveZeroes(vector<int>& nums) {

        vector<int> nonZeroElements;

        // 将vec中所有非0元素放入nonZeroElements中
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] )
                nonZeroElements.push_back( nums[i] );

        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
        for( int i = 0 ; i < nonZeroElements.size() ; i ++ )
            nums[i] = nonZeroElements[i];

        // 将nums剩余的位置放置为0
        for( int i = nonZeroElements.size() ; i < nums.size() ; i ++ )
            nums[i] = 0;
    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}