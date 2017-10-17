/*
把二叉树打印成多行

时间限制：1秒 空间限制：32768K 

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

//运行时间：3ms 占用内存：500K

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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> vec;
            if( pRoot == NULL )
                return vec;
            queue<TreeNode*> q;
            q.push(pRoot);
            
            while( !q.empty() ){
                int lo = 0, hi = q.size();
                vector<int> c;
                while( lo++ < hi ){
                    TreeNode *t = q.front();
                    q.pop();
                    c.push_back( t->val );
                    if( t->left )
                        q.push( t->left );
                    if( t->right )
                        q.push( t-> right );
                }
                
                vec.push_back(c);
            }
            return vec;
        }
};
