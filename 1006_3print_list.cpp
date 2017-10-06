/*
时间限制：1秒 空间限制：32768K 热度指数：348390
本题知识点： 链表

题目描述
输入一个链表，从尾到头打印链表每个节点的值。

*/

//运行时间：1ms， 占用内存：504k

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> result;
        stack<int> arr;
        ListNode* p=head;
        while(p!=NULL){
            arr.push(p->val);
            p=p->next;
        }
        int len=arr.size();
        for(int i=0;i<len;i++){
            result.push_back(arr.top());
            arr.pop();
        }
        
        return result;
    }
 };
