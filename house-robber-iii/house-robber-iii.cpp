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
    pair<int,int> recur(TreeNode* root)
    {
        if (root == NULL){return {0,0};}
        pair<int,int> p = recur(root->left);
        pair<int,int> q = recur(root->right);
        int x = root->val + p.second + q.second;
        int y = (max(p.first,p.second) + max(q.first,q.second));
        x = max(x,y);
        return make_pair(x,y);
    }

    int rob(TreeNode* root) {
        return recur(root).first;
    }
};