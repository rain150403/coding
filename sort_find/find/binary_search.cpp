#include <iostream>
using namespace std;

int binary_search( int* a, int len, int goal );

int main(){
	const int LEN = 10000;
	int a[LEN];

	for( int i = 0; i < LEN; i++ )
		a[i] = i - 5000;
	int target = 0;
	int index = binary_search( a, LEN, target );

	if( index ！=  -1 )
		cout << target << "在数组中的下标为" << index << endl;
	else
		cout << "不存在" << target << endl;

	return 0;
}

int binary_search( int* a, int len, int goal ){
	int low = 0;
	int high = len - 1;
	while( low <= high ){
		int middle = ( high - low ) / 2 + low;//直接使用 ( high + low ) / 2 可能导致溢出
		if ( a[middle] == goal )
			return middle;
		else if ( a[middle] > goal )
			high = middle - 1;
		else
			low = middle + 1;
	}

	return -1;
}

//多看几遍，就记住了
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
int binarySearch( T arr[], int n, T target ){

    int l = 0, r = n; // target在[l...r)的范围里
    while( l < r ){    // 当 l == r时,区间[l...r)是一个无小区间
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( target > arr[mid] )
            l = mid + 1;    // target在[mid+1...r)中; [l...mid]一定没有target
        else// target < arr[mid]
            r = mid;        // target在[l...mid)中; [mid...r)一定没有target
    }

    return -1;
}

int main() {

    int n = pow(10,7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for( int i = 0 ; i < n ; i ++ )
        assert( i == binarySearch(data, n, i) );
    clock_t endTime = clock();

    cout<<"binarySearch2 test complete."<<endl;
    cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}

//要想把二分搜索写完全正确，也要用心
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "util.h"

using namespace std;

template<typename T>
int binarySearch( T arr[], int n, T target ){

    int l = 0, r = n-1; // 在[l...r]的范围里寻找target
    while( l <= r ){    // 当 l == r时,区间[l...r]依然是有效的
        int mid = l + (r-l)/2;
        if( arr[mid] == target ) return mid;
        if( target > arr[mid] )
            l = mid + 1;  // target在[mid+1...r]中; [l...mid]一定没有target
        else    // target < arr[mid]
            r = mid - 1;  // target在[l...mid-1]中; [mid...r]一定没有target
    }

    return -1;
}

int main() {

    int n = pow(10,7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for( int i = 0 ; i < n ; i ++ )
        assert( i == binarySearch(data, n, i) );
    clock_t endTime = clock();

    cout<<"binarySearch test complete."<<endl;
    cout<<"Time cost: "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
