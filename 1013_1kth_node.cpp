/*
时间限制：1秒 空间限制：32768K

题目描述
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

//运行时间：3ms  占用内存：624k

//中序遍历，看似简单，实际还是有点细节需要注意，并且需要掌握递归这一技巧！！！

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if( pRoot == NULL || k == 0 )
            return NULL;
        
        return KthNodeCore(pRoot, k);
    }
    
    TreeNode* KthNodeCore( TreeNode* pRoot, int& k ){
        TreeNode* target = NULL;
        
        if( pRoot->left != NULL )
            target = KthNodeCore( pRoot->left, k );
        
        if( target == NULL ){
            if( k == 1 )
                target = pRoot;
            k--;
        }
        
        if( target == NULL && pRoot->right != NULL )
            target = KthNodeCore( pRoot->right, k );
        
        return target;
    }
};
