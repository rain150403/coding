/*
时间限制：1秒 空间限制：32768K
本题知识点： 排序 链表 leetcode

题目描述

Sort a linked list in O(n log n) time using constant space complexity.
*/

//运行时间：12ms 占用内存：1008k

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
    ListNode *sortList(ListNode *head) {
        if( !head || !head->next )
            return head;
        ListNode* p = head, *q = head->next;
        while( q && q->next ){
            p = p->next;
            q = q->next->next;
        }
        ListNode* left = sortList( p->next );
        p->next = NULL;
        ListNode* right = sortList( head );
        
        return merge( left, right );
    }
    
    ListNode* merge( ListNode* left, ListNode* right ){
        ListNode dummy(0);
        ListNode *p = &dummy;
        while( left && right ){
            if( left->val < right->val ){
                p->next = left;
                left = left->next;
            }else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if( left )
            p->next = left;
        if( right )
            p->next = right;
        return dummy.next;
    }
};
