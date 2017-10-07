/*
时间限制：1秒 空间限制：32768K 
本题知识点： 栈

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
//运行时间：1ms， 占用内存：500K

class Solution {
public:
    void push(int value) {
        stk.push(value);
        if( stk_min.empty() ){
            stk_min.push(value);
        }else if( value < stk_min.top() ){
            stk_min.push(value);
        }
    }
    void pop() {
        if( stk.top() == stk_min.top() )
            stk_min.pop();
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return stk_min.top();
    }
private:
    stack<int> stk;
    stack<int> stk_min;
 };
