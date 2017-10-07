/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表

题目描述
输入一个链表，反转链表后，输出链表的所有元素。
*/

//运行时间：1ms 占用内存：500K

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pReversedHead = NULL;
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;
        while( pNode != NULL ){
            ListNode* pNext = pNode->next;
            if( pNext == NULL )
                pReversedHead = pNode;
            
            pNode->next = pPrev;  //这里要小心，好好理解
            
            pPrev = pNode;
            pNode = pNext;  //以上三句话很重要
        }
        
        return pReversedHead;
    }
};
