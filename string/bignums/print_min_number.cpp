链接：https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993
来源：牛客网

/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼成的所有数字中最小的一个。
*/


class Solution {
public:
    static bool compare( const string &st1,const string &st2){
        string s1 = st1+st2;
        string s2 = st2+st1;
        return s1<s2;
    }
    string PrintMinNumber(vector<int> numbers) {
         string result;
        if(numbers.size()<=0){
            return result;
        }
        vector<string> strNum;
        for(int i=0;i<numbers.size();i++ ){
           stringstream ss;
            ss<<numbers[i];
            string s = ss.str();
            strNum.push_back(s);
        }
        sort(strNum.begin(),strNum.end(),compare);
        
        for(int i=0;i<strNum.size();i++){
            result.append(strNum[i]);
        }
        return result;
         
    }
};
