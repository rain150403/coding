/*
时间限制：1秒 空间限制：32768K

题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

//运行时间：2ms 占用内存：628k

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if( pRoot == NULL )
            return 0;
        
        int nLeft = TreeDepth( pRoot->left );
        int nRight = TreeDepth( pRoot->right );
        
        return ( nLeft > nRight )? ( nLeft+1 ):( nRight+1 );
    }
};
