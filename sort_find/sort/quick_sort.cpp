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
