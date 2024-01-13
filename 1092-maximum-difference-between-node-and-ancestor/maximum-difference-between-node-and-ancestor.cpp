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

    int recur(TreeNode* root,int Max, int Min)
    {
        if (root == NULL){return 0;}
        int ans = 0;
        Max = (root->val > Max)?root->val:Max;
        Min = (root->val < Min)?root->val:Min;
        ans = max(Max - root->val,ans);
        ans = max(root->val - Min,ans);
        ans = max(recur(root->left,Max,Min),ans);
        ans = max(recur(root->right,Max,Min),ans);
        return ans;
    }

    int maxAncestorDiff(TreeNode* root) {
        return max(recur(root->left,root->val,root->val),recur(root->right,root->val,root->val));
    }
};