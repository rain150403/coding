/*
时间限制：1秒 空间限制：32768K 热度指数：154500
本题知识点： 队列 栈

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//运行时间：1ms， 占用内存：368K

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
         
    }
 
    int pop() {
        int res;
        if (stack2.size() > 0) {
            res = stack2.top();
            stack2.pop();
        }
        else if (stack1.size() > 0) {
            while (stack1.size() > 0) {
                int ele = stack1.top();
                stack1.pop();
                stack2.push(ele);
            }
            res = stack2.top();
            stack2.pop();
        }
        return res;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};
