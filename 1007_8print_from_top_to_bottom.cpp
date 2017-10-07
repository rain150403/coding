/*
时间限制：1秒 空间限制：32768K 

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

//运行时间：1ms 占用内存：500K

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include<queue>
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(root == NULL)
            return v;
        q.push(root);
        while(!q.empty())
            {root = q.front();
             q.pop();
             v.push_back(root->val);
             if(root->left)
                 q.push(root->left);
             if(root->right)
                 q.push(root->right);
        }
        return v;
    }
};
