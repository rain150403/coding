/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表

题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if( pListHead == NULL || k == 0 )
            return NULL;
        
        ListNode *pAhead = pListHead;
        ListNode *pBehind = NULL;
        
        for( unsigned int i = 0; i < k-1; ++i ){
            if( pAhead->next != NULL )
                pAhead = pAhead->next;
            else
                return NULL;
        }
        
        pBehind = pListHead;
        while( pAhead->next != NULL ){
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};
