链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e
来源：牛客网

边界条件：
数据上下 溢出
空字符串
只有正负号
有无正负号
错误标志输出

class Solution {
public:
    enum Status{kValid = 0,kInvalid};
    int g_nStatus = kValid;
     
    int StrToInt(string str) {
      g_nStatus = kInvalid;
        long long num = 0;
        const char* cstr = str.c_str();
        if( (cstr != NULL) && (*cstr != '\0') )
        {
            int minus = 1;
            if(*cstr == '-')
            {
                minus = -1;
                cstr++;
            }
            else if(*cstr == '+')
                cstr++;
             
            while(*cstr != '\0')
            {
                if(*cstr > '0' && *cstr < '9')
                {
                    g_nStatus = kValid;
                    num = num*10 + (*cstr -'0');
                    cstr++;
                    if( ((minus>0) && (num > 0x7FFFFFFF)) ||
                        ((minus<0) && (num > 0x80000000)) )
                    {
                        g_nStatus = kInvalid;
                        num = 0;
                        break;
                    }
                }
                else
                {
                    g_nStatus = kInvalid;
                    num = 0;
                    break;
                }
            }
             
            if(g_nStatus == kValid)
                num = num * minus;
             
        }
        return (int)num;
    }
};
