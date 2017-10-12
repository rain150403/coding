/*
时间限制：1秒 空间限制：32768K 
本题知识点： 字符串

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

//运行时间：1ms 占用内存：496K

class Solution {
public:
    bool isNumeric(char* string)
    {
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
            
            //for integers
            else if( *string == 'e' || *string == 'E' )
                numeric = isExponential( &string );
            else
                numeric = false;
        }
        
        return numeric && *string == '\0';
    }
    
    void scanDigits( char** string ){
        while( **string != '\0' && **string >= '0' && **string <= '9' )
            ++(*string);
    }
    
    bool isExponential( char** string ){
        
        if(**string != 'e' && **string != 'E' )
            return false;
        
        ++(*string);
        if( **string == '+' || **string == '-' )
            ++(*string);
        
        if( **string == '\0' )
            return false;
        
        scanDigits( string );
        return (**string == '\0' ) ? true : false;
    }
};
