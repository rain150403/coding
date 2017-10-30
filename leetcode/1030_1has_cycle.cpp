/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表 leetcode

题目描述

Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
*/

//运行时间：12ms 占用内存：1012k

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
    bool hasCycle(ListNode *head) {
        if( head == NULL )
            return false;
        ListNode *n1 = head;
        ListNode *n2 = head;
        while( n2->next != NULL && n2->next->next != NULL ){
            n1 = n1->next;
            n2 = n2->next->next;
            if( n1 == n2 )
                return true;
        }
        return false;
    }
};
