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
    int m = 0;

    int func(TreeNode * root)
    {
        if (root == NULL){return 0;}
        int a = func(root->left), b = func(root->right);
        m = max(m,a+b);
        return max(a,b)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return max(func(root)-1,m);
    }
};