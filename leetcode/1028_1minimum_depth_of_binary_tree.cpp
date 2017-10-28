/*
时间限制：1秒 空间限制：32768K
本题知识点： 树

题目描述
Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

//运行时间：8ms 占用内存：884k


//采用广度优先搜索，或者层序遍历，找到的第一个叶节点的深度即是最浅。
//看了很多答案都是用的深度优先遍历，我觉得这个题用层序更效率更高，因为它不需要去遍历所有的节点，一旦找到一个叶节点，它肯定是最短的。
class Solution {
public:
    typedef TreeNode* tree;
    
    int run(TreeNode *root) {
        if( !root )
            return 0;
        queue<tree> qu;
        tree last, now;
        int level, size;
        last = now = root;
        level = 1;
        qu.push(root);
        while( qu.size() ){
            now = qu.front();
            qu.pop();
            size = qu.size();
            if( now->left )
                qu.push( now->left );
            if( now->right )
                qu.push( now->right );
            if( qu.size() - size == 0 )
                break;
            if( last == now ){
                level++;
                if( qu.size() )
                    last = qu.back();
            }
        }
        return level;
    }
};

//运行时间：18ms 占用内存：896k
class Solution {
public:
    int run(TreeNode *root) {
        if( !root )
            return 0;
        int l = run( root->left );
        int r = run( root->right );
        if( l == 0 || r == 0 )
            return 1 + l + r;
        return 1 + min( l, r );
    }
};
