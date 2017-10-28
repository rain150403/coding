/*
时间限制：1秒 空间限制：32768K 
本题知识点： 树 leetcode

题目描述

Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
*/

//运行时间：3ms 占用内存：500k

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
    vector<int> res;
    void helper( TreeNode* root ){
        if( root == NULL )
            return;
        res.push_back( root->val );
        helper( root->left );
        helper( root->right );
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        helper( root );
        return res;
    }
};

//运行时间：1ms 占用内存：496k
//比递归快
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack< TreeNode* > s;
        if( root == NULL ){
            return res;
        }
        s.push( root );
        while( !s.empty() ){
            TreeNode* cur = s.top();
            s.pop();
            res.push_back( cur->val );
            if( cur->right != NULL )
                s.push( cur->right );
            if( cur->left != NULL )
                s.push( cur->left );
        }
        return res;
    }
};
