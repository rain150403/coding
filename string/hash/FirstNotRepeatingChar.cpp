/*
题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。

我们试着去找一个更快的方法。由于题目与字符出现的次数相关，我们是不是可以统计每个字符在该字符串中出现的次数？要达到这个目的，我们需要一个数据容器来存放每
个字符的出现次数。在这个数据容器中可以根据字符来查找它出现的次数，也就是说这个容器的作用是把一个字符映射成一个数字。在常用的数据容器中，哈希表正是这个
用途。
由于字符（char）是一个长度为8的数据类型，因此总共有可能256 种可能。于是我们创建一个长度为256的数组，每个字母根据其ASCII码值作为数组的下标对应数组的对
应项，而数组中存储的是每个字符对应的次数。这样我们就创建了一个大小为256，以字符ASCII码为键值的哈希表。（256个字符我们建立一个256个数组，数组用来存放字
符的次数，使用字符的ASCII值作为数组的下标）
我们第一遍扫描这个数组时，每碰到一个字符，在哈希表中找到对应的项并把出现的次数增加一次。这样在进行第二次扫描时，就能直接从哈希表中得到每个字
符出现的次数了。
*/

char FirstNotRepeatingChar( char* pString ){
	//invalid input
	if( !pString )
		return '\0';

	// 1. 初始化
	const int tableSize = 256;
	unsigned int hashTable[tableSize]; 
	for( unsigned int i = 0; i < tableSize; ++i )
		bashTable[i] = 0;

	// 2. 以字符的ASCII作为数组下标， 求每个字符出现的次数
	char* pHashKey = pString;
	while( *(pHashKey) != '\0' )
		hashTable[ *(pHashKey++) ]++;

	// 3. 找到第一次出现一次的字符，就是在数组中第一次存储为1所对应的字符
	pHashKey = pString;
	while( *pHashKey != '\0' ){
		if( hashTable[*pHashKey] == 1 )
			return *pHashKey;

		pHashKey++;
	}

	//if the string is empty
	//or every char in the string appears at least twice
	return '\0';
}
