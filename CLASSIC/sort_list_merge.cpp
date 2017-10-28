/*
时间限制：1秒 空间限制：32768K
本题知识点： 排序 链表 leetcode
题目描述
Sort a linked list in O(n log n) time using constant space complexity.
*/

//运行时间：12ms 占用内存：1008k

/*
因为题目要求复杂度为O(nlogn),故可以考虑归并排序的思想。
归并排序的一般步骤为：
1）将待排序数组（链表）取中点并一分为二；
2）递归地对左半部分进行归并排序；
3）递归地对右半部分进行归并排序；
4）将两个半部分进行合并（merge）,得到结果。
所以对应此题目，可以划分为三个小问题：
1）找到链表中点 （快慢指针思路，快指针一次走两步，慢指针一次走一步，快指针在链表末尾时，慢指针恰好在链表中点）；
2）写出merge函数，即如何合并链表。 （见merge-two-sorted-lists 一题解析）
3）写出mergesort函数，实现上述步骤。
*/

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
