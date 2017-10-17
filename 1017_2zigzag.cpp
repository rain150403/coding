/*
按之字形顺序打印二叉树

时间限制：1秒 空间限制：32768K 

题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

//运行时间：2ms 占用内存：500k

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
        vector<vector<int>> res;
        if( pRoot == NULL )
            return res;
        queue< TreeNode* > que;
        que.push( pRoot );
        bool even = false;
        while( !que.empty() ){
            vector<int> vec;
            const int size = que.size();
            for( int i = 0; i < size; i++ ){
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back( temp->val );
                if( temp->left != NULL )
                    que.push( temp->left );
                if( temp->right != NULL )
                    que.push( temp->right );
            }
            
            if( even )
                reverse( vec.begin(), vec.end() );
            res.push_back( vec );
            even = !even;
        }
        
        return res;
    }
    
};

//运行时间：1ms 占用内存： 496k
//使用栈来实现，需要注意的地方很多，思想其实都差不多
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
        vector<vector<int>> result;
        if( pRoot == NULL )
            return result;
        stack<TreeNode*> stack1, stack2;
        stack1.push(pRoot);
        while( !stack1.empty() || !stack2.empty() ){
            if( !stack1.empty() ){
                vector<int> temp;
                while( !stack1.empty() ){
                    TreeNode* data = stack1.top();
                    stack1.pop();
                    temp.push_back( data->val );
                    if( data->left != NULL )
                        stack2.push( data->left );
                    if( data->right != NULL )
                        stack2.push( data->right );
                }
                result.push_back( temp );
            }
            
            if( !stack2.empty() ){
                vector<int> temp;
                while( !stack2.empty() ){
                    TreeNode* data = stack2.top();
                    stack2.pop();
                    temp.push_back( data->val );
                    if( data->right )
                        stack1.push( data->right );
                    if( data->left )
                        stack1.push( data->left );
                }
                
                result.push_back( temp );
            }
        }
        return result;
    }
    
};
