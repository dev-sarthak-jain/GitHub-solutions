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

    int ans = 0;
    int l,h;
    void func(TreeNode* root)
    {
        if (root == NULL){return;}
        if (root->val>=l && root->val <= h){ans+=root->val;}
        if (root->val>=l){func(root->left);}
        if (root->val<=h){func(root->right);}
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        func(root);
        return ans;
    }
};