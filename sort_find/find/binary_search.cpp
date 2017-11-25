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
