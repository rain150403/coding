/*时间限制：1秒 空间限制：32768K

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/

//运行时间：3ms 占用内存：500k

class Solution {
public:
    int TreeDepth( const TreeNode* pRoot ){
        if( pRoot == NULL )
            return 0;
        
        int nLeft = TreeDepth( pRoot->left );
        int nRight = TreeDepth( pRoot->right );
        
        return ( nLeft > nRight ) ? ( nLeft + 1 ) : ( nRight + 1 );
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if( pRoot == NULL )
            return true;
        
        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );
        
        int diff = left - right;
        if( diff > 1 || diff < -1 )
            return false;
        
        return IsBalanced_Solution( pRoot->left ) && IsBalanced_Solution( pRoot->right );
    }
};
