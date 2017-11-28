/*
给定一个有序整形数组和一个整数target，寻找两个元素，使其和为target， 返回这两个数的索引。
*/

//方法三：对撞指针
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        int l = 0, r = numbers.size()-1;
        while( l < r ){

            if( numbers[l] + numbers[r] == target ){
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            }
            else if( numbers[l] + numbers[r] < target )
                l ++;
            else // numbers[l] + numbers[r] > target
                r --;
        }

        throw invalid_argument("the input has no solution");
    }

};

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum( vec, target );
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}

//方法二：应用二分搜索
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        for( int i = 0 ; i < numbers.size() - 1 ; i ++ ){

            int j = binarySearch( numbers, i+1, numbers.size()-1, target - numbers[i] );
            if( j != -1 ){
                int res[2] = {i+1, j+1};
                return vector<int>(res, res+2);
            }
        }

        throw invalid_argument("the input has no solution");
    }

private:
    int binarySearch( vector<int> &nums, int l, int r, int target){

        assert( l >= 0 && l < nums.size() );
        assert( r >= 0 && r < nums.size() );

        while( l <= r ){

            int mid = l + (r-l)/2;
            if( nums[mid] == target )
                return mid;

            if( target > nums[mid] )
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

};

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum( vec, target );
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}

//方法一：普通两重循环搜索
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 时间复杂度: O(n^2)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        for( int i = 0 ; i < numbers.size() ; i ++ )
            for( int j = i+1 ; j < numbers.size() ; j ++ )
                if( numbers[i] + numbers[j] == target ){
                    int res[2] = {i+1, j+1};
                    return vector<int>(res, res+2);
                }


        throw invalid_argument("the input has no solution");
    }

};

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum( vec, target );
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
