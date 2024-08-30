/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* &p, TreeNode* &q)
    {
        bool a = (p==NULL), b = (q==NULL);
        if (b){return;}
        else if (a){p=q;return;}
        p->val+=q->val;
        func(p->left,q->left);
        func(p->right,q->right);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        func(root1,root2);
        return root1;
    }
};