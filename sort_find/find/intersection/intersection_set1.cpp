/*
改动的地方：
把数组一的数据存放到set里面：set<int> record( nums1.begin(), nums1.end() );
把set2的数据存放到vector中：return vector<int>( resultSet.begin(), resultSet.end() );
只是看起来更清晰了，实现的功能不变。
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/// intersection of two arrays
class Solution{
public:
	vector<int> intersection( vector<int>& nums1, vector<int>& nums2 ){
		set<int> record( nums1.begin(), nums1.end() );

		set<int> resultSet;
		for( int i = 0; i < nums2.size(); i++ )
			if( record.find( nums2[i] ) != record.end() )
				resultSet.insert( nums2[i] );

		return vector<int>( resultSet.begin(), resultSet.end() );
	}
};

int main(){
	int nums1[] = { 1, 2, 2, 1 };
	vector<int> vec1( nums1, nums2 + sizeof(nums1) / sizeof(int) );

	int nums2[] = { 2, 2 };
	vector<int> vec2( nums2, nums2 + sizeof(nums2) / sizeof(int) );

	vector<int> res = Solution().intersection( vec1, vec2 );
	for( int i = 0; i < res.size(); i++ )
		cout << res[i] << " ";
	cout << endl;

	return 0;
} 
