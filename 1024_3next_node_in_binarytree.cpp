/*
时间限制：1秒 空间限制：32768K

题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

//运行时间：1ms 占用内存：500k

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if( pNode == nullptr )
            return nullptr;
        
        TreeLinkNode* pNext = nullptr;
        if( pNode->right != nullptr ){
            TreeLinkNode* pRight = pNode->right;
            while( pRight->left != nullptr )
                pRight = pRight->left;
            
            pNext = pRight;
        }
        else if( pNode->next != nullptr ){
            TreeLinkNode* pCurrent = pNode;
            TreeLinkNode* pParent = pNode->next;
            while( pParent != nullptr && pCurrent == pParent->right ){
                pCurrent = pParent;
                pParent = pParent->next;
            }
            
            pNext = pParent;
        }
        
        return pNext;
    }
};
