/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//运行时间：1ms 占用内存：500k

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if( pHead == NULL )
            return pHead;
        
        ListNode *pre = NULL;
        ListNode *p = pHead;
        ListNode *q = NULL;
        
        while( p != NULL ){
            if( p->next != NULL && p->next->val == p->val ){
                q = p->next;
                while( q != NULL && q->next != NULL && q->next->val == p->val ){
                    q = q->next;
                }
                
                if( p == pHead ){
                    pHead = q->next;
                }
                else{
                    pre->next = q->next;
                }
                p = q->next;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return pHead;
    }
};
