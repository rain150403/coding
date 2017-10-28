/*
时间限制：1秒 空间限制：32768K
本题知识点： 排序 leetcode

题目描述

Sort a linked list using insertion sort.
*/

//运行时间：8ms 占用内存：1144k

// 1. 添加了个伪链表头，简化设计
// 2. 利用递归

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
    ListNode *insertionSortList(ListNode *head) {
        if( !head || !head->next )
            return head;
        ListNode dummyHead( 0 ), *p;
        dummyHead.next = insertionSortList( head->next );
        p = &dummyHead;
        
        while( p && p->next && head->val > p->next->val ){
            p = p->next;
        }
        head->next = p->next;
        p->next = head;
        
        return dummyHead.next;
    }
};

//运行时间：11ms 占用内存：888k
//用这种自带方法，比递归占内存小
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
    ListNode *insertionSortList(ListNode *head) {
        if( head == NULL || head->next == NULL )
            return head;
        list<int> v;
        for( ListNode *p = head; p != NULL; p = p->next ){
            v.push_back( p->val );
        }
        v.sort();
        for( ListNode *p = head; p != NULL; p = p->next ){
            p->val = v.front();
            v.pop_front();
        }
        return head;
    }
};

