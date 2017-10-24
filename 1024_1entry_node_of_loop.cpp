/*时间限制：1秒 空间限制：32768K
本题知识点： 链表

题目描述
一个链表中包含环，请找出该链表的环的入口结点。*/

//运行时间：1ms  占用内存：500k

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
    ListNode* MeetingNode( ListNode* pHead ){
        if( pHead == nullptr )
            return nullptr;
        
        ListNode* pSlow = pHead->next;
        if( pSlow == nullptr )
            return nullptr;
        
        ListNode* pFast = pSlow->next;
        while( pFast != nullptr && pSlow != nullptr ){
            if( pFast == pSlow )
                return pFast;
            
            pSlow = pSlow->next;
            
            pFast = pFast->next;
            if( pFast != nullptr )
                pFast = pFast->next;
        }
        return nullptr;
    }
    
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetingNode = MeetingNode(pHead);
        if( meetingNode == nullptr )
            return nullptr;
        
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while( pNode1->next != meetingNode ){
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        
        pNode1 = pHead;
        for( int i = 0; i < nodesInLoop; ++i )
            pNode1 = pNode1->next;
        
        ListNode* pNode2 = pHead;
        while( pNode1 != pNode2 ){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        
        return pNode1;
    }
};
