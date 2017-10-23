/*
时间限制：1秒 空间限制：32768K
本题知识点： 链表

题目描述
输入两个链表，找出它们的第一个公共结点。
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

//方法一：
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};

//方法二：
class Solution {
public:
    unsigned int GetListLength( ListNode* pHead ){
        unsigned int nLength = 0;
        ListNode* pNode = pHead;
        while( pNode != nullptr ){
            ++nLength;
            pNode = pNode->next;
        }
        return nLength;
    }
    
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unsigned int nLength1 = GetListLength(pHead1);
        unsigned int nLength2 = GetListLength(pHead2);
        int nLengthDif = nLength1 - nLength2;
        
        ListNode* pListHeadLong = pHead1;
        ListNode* pListHeadShort = pHead2;
        if( nLength2 > nLength1 ){
            pListHeadLong = pHead2;
            pListHeadShort = pHead1;
            nLengthDif = nLength2 - nLength1;
        }
        
        for( int i = 0; i < nLengthDif; ++i )
            pListHeadLong = pListHeadLong->next;
        while( (pListHeadLong != nullptr )&&(pListHeadShort != nullptr )&&(pListHeadLong != pListHeadShort) ){
            pListHeadLong = pListHeadLong->next;
            pListHeadShort = pListHeadShort->next;
        }
        
        ListNode* pFirstCommonNode = pListHeadLong;
        
        return pFirstCommonNode;
    }
};
