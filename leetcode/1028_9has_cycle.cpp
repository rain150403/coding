/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表 leetcode

题目描述

Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.
Follow up:
Can you solve it without using extra space?
*/

//运行时间：11ms 占用内存：1264k

//判断链表是否有环

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool hasCycle( ListNode* head ){
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast != NULL && fast->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow )
                return true;
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if( hasCycle(head) ){
            ListNode *temp = NULL;
            while( head ->next ){
                temp = head->next;
                head->next = NULL;
                head = temp;
            }
            return head;
        }else{
            return NULL;
        }
    }
};
