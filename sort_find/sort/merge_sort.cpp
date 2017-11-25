void mergeSort( int[] data, int low, int high ){
	if( data == null || low < 0 || high >= data.length )
		throw new RuntimeException( "Invalid Parameters!" );

	if( low < high ){
		int mid = ( low + high ) / 2;
		mergeSort( data, low, mid );
		mergeSort( data, mid + 1, high );
		merge( data, low, mid, high );
	}
}

void merge( int[] data, int low, int mid, int high ){
	int startFirst = low, endFirst = mid, startSecond = mid + 1, endSecond = high;
	int[] tmp = new int[data.length];
	int i = startFirst, j = startSecond, index = startFirst;
	while( i <= endFirst && j <= endSecond )
		if( data[i] < data[j] )
			tmp[index++] = data[i++];
		else
			tmp[index++] = data[j++];

	while( i <= endFirst )
		tmp[index++] = data[i++];

	while( j <= endSecond )
		tmp[index++] = data[j++];

	for( index = low; index <= high; index++ )
		data[index] = tmp[index];
}
