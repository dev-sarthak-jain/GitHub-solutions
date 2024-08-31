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
    bool ans = 0;
    void func(TreeNode* root,int targetSum, int x)
    {
        if (ans == 1){return;}
        if (root->left == NULL && root->right == NULL)
        {
            x+=root->val;
            if (x == targetSum){ans = 1;}
            return;
        }
        if (root->left != NULL)
        {
            func(root->left,targetSum,x+root->val);
        }
        if (root->right != NULL)
        {
            func(root->right,targetSum,x+root->val);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL){return 0;}
        func(root,targetSum,0);
        return ans;
    }
};