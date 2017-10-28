/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表 leetcode

题目描述

Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…
You must do this in-place without altering the nodes' values.
For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
*/

//运行时间：23ms 占用内存：1792k
//看清楚哦，不是反转链表，而是交叉的哦~
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if( !head )
            return;
        vector<int> V;
        ListNode* ptr = head;
        while( ptr != NULL ){
            V.push_back( ptr->val );
            ptr = ptr->next;
        }
        
        int i = 0;
        int j = V.size() - 1;
        int flag = 0;
        ptr = head;
        while( i <= j ){
            if( ( flag % 2 ) == 0 ){
                ptr->val = V[i];
                i += 1;
            }
            else{
                ptr->val = V[j];
                j -= 1;
            }
            ++flag;
            
            ptr = ptr->next;
        }
    }
};//人到了一定的年龄就会想念家庭，并且希望其他人也能感同身受吧
