/*
时间限制：1秒 空间限制：32768K
本题知识点： 树 leetcode

题目描述

Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
*/

//运行时间：3ms 占用内存：632k
//说是不让用递归的，但还是通过了
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void postOrder( TreeNode *root, vector<int> &vec ){
        if( root != NULL ){
            postOrder( root->left, vec );
            postOrder( root->right, vec );
            vec.push_back( root->val );
        }//即使蒙着眼睛，只要心中有爱，我也能找到家
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        postOrder( root, vec );
        return vec;
    }
};

// 巧妙的方法：前序遍历 根->左->右 变成 根->右->左 结果再reverse一下
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if( !root )
            return res;
        stack<TreeNode *> st;
        st.push( root );
        while( st.size() ){
            TreeNode *temp = st.top();
            st.pop();
            res.push_back( temp->val );
            if( temp->left )
                st.push( temp->left );
            if( temp->right )
                st.push( temp->right );
        }
        
        reverse( res.begin(), res.end() );
        return res;
    }
};

//运行时间：1ms 占用内存：500k
//非递归方法

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        if( root == NULL )
            return vec;
        stack< TreeNode* > st;
        st.push( root );
        
        TreeNode* cur = NULL;
        
        while( !st.empty() ){
            cur = st.top();
            if( cur->left == NULL && cur->right == NULL ){
                vec.push_back( cur->val );
                st.pop();
            }else{
                if( cur->right ){
                    st.push( cur->right );
                    cur->right = NULL;
                }
                if( cur->left ){
                    st.push( cur->left );
                    cur->left = NULL;
                }
            }
        }
        return vec;
    }
};
