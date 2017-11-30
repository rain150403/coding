/*
今天才算是真正明白快排。

以第一个元素为指标，从小到大排列：
两个指针一个指头start，一个指尾end，指向标准的指针不动，后面的指针向前找小于标准的，前面的指针向后找大于标准的，交替进行。直到两个指针重合。

从大到小排列则相反。

其实质就是找到一个标杆，然后遍历整个数组，比标杆大的放到一边，小的放到另一边，什么叫放到一边，就是交换两个数。
*/


void quickSort( int[] data, int length, int start, int end ){
	if( start == end )
		return ;

	int index = partition( data, length, start, end );
	if( index > start )
		quickSort( data, length, start, index - 1 );
	if( index < end )
		quickSort( data, length, index + 1, end );
}

int partition( int[] data, int length, int start, int end ){
	if( data == null || length <= 0 || start < 0 || start >= length )
		throw new RuntimeException( "Invalid Parameters" );

	int index  = randomInRange( start, end );
	swap( data, index, end );

	int small = start - 1;
	for( index = start; index < end; index++ )
		if( data[index] < data[end] ){
			++small;
			if( small ！= index )
				swap( data, small, index );
		}

	++small;
	swap( data, small, end );

	return small;
}

int randomInRange( int start, int end ){
	return new Random().nextInt( end - start + 1 ) + start;
}

void swap( int[] data, int a, int b ){
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}
