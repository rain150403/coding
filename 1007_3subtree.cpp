/*
时间限制：1秒 空间限制：32768K

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

//运行时间：1ms 占用内存:500k

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
    bool DoesTree1HaveTree2( TreeNode* pRoot1, TreeNode* pRoot2 ){
        if( pRoot2 == NULL )
            return true;
        if( pRoot1 == NULL )
            return false;
        
        if( pRoot1->val != pRoot2->val )
            return false;
        
        return DoesTree1HaveTree2( pRoot1->left, pRoot2->left ) && DoesTree1HaveTree2( pRoot1->right, pRoot2->right );
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        
        if( pRoot1 != NULL && pRoot2 != NULL ){
            
            if( pRoot1->val == pRoot2->val )
                result = DoesTree1HaveTree2( pRoot1, pRoot2 );
            if( !result )
                result = HasSubtree( pRoot1->left, pRoot2 );
            if( !result )
                result = HasSubtree( pRoot1->right, pRoot2 );
        }
        
        return result;
    }
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1)
            return false;
        if(!pRoot2)
            return false;
        return ( dfs(pRoot1,pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
private:
    bool dfs(TreeNode * r1, TreeNode * r2){
        if(!r2)
            return true;      //应该是空树是任意树的子结构吧？？？
        if(!r1)
            return false;
        if(r1->val != r2->val)
            return false;
        return dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
    }
};
