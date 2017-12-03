/*
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、“3.1416”及“-1E-16”都表示数值，但"12e“、
”1a3.14"、“1.2.3”、“+-5”及“12e+5.4”都不是。
思路：表示数值的字符串遵循如下模式：[sign]integral-digits[.[fractional-digits]][e|E[sign]exponential-digits] （'['和']'之间的为可有可无的部分）。
判断一个字符是否符合上述模式时，首先看第一个字符是不是正负号。如果是，在字符串上移动一个字符，继续扫描剩余的字符串中0到9的位数。如果是一个小数，则将遇
上小数点。另外，如果是用科学计数法表示的数值，在整数或者小数的后面还有可能遇到'e'或者'E'。整个过程用代码实现如下：
*/

bool isNumeric( char* string ){
	if( string == NULL )
		return false;

	if( *string == '+' || *string == '-' )
		++string;
	if( *string == '\0' )
		return false;

	bool numeric = true;
	scanDigits( &string );

	if( *string != '\0' ){
		// for float
		if( *string == '.' ){
			++string;
			scanDigits( &string );
			if( *string == 'e' || *string == 'E' )
				numeric = isExponential( &string );
		}
		// for integers
		else if( *string == 'e' || *string == 'E' )
			numeric = isExponential( &string );
		else
			numeric = false;
	}  

	return numeric && *string == '\0';
}

void scanDigits( char** string ){
	while( **string != '\0' && **string >= '0' && **string <= '9' )
		++( *string );
}

bool isExponential( char** string ){
	if( **string != 'e' && **string != 'E' )
		return false;

	++( *string );
	if( **string == '+' || **string == '-' )
		++( *string );

	if( **string == '\0' )
		return false;

	scanDigits( string );
	return ( **string == '\0' ) ? true: false;
}
