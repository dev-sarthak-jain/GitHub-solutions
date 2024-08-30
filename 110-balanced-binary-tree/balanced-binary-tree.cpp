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
    bool ans = 1;
    int height(TreeNode* root)
    {
        if (root == NULL){return 0;}
        int a = height(root->left), b = height(root->right);
        if (ans == 0){return -1;}
        if (abs(a-b)>1){ans = 0;return -1;}
        return max(a,b)+1;
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;

    }
};