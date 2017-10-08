/*
时间限制：1秒 空间限制：32768K 
本题知识点： 链表

题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

//运行时间： 1ms, 占用内存：500K

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes( pHead );
        ConnectSiblingNodes( pHead );
        return ReconnectNodes( pHead );
    }
    
    RandomListNode* ReconnectNodes( RandomListNode* pHead ){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        
        if( pNode != NULL ){
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        
        while( pNode != NULL ){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    
    void ConnectSiblingNodes( RandomListNode* pHead ){
        RandomListNode* pNode = pHead;
        while( pNode != NULL ){
            RandomListNode* pCloned = pNode->next;
            if( pNode->random != NULL ){
                pCloned->random = pNode->random->next;
            }
            pNode = pCloned->next;
        }
    }
    
    void CloneNodes( RandomListNode* pHead ){
        RandomListNode* pNode = pHead;
        while( pNode != NULL ){
            RandomListNode* pCloned = new RandomListNode( pNode->label );
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;
            
            pNode->next = pCloned;
            
            pNode = pCloned->next;
        }
    }
};
