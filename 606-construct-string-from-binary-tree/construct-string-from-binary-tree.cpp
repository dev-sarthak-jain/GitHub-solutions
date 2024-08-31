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
    string ans = "";

    void func(TreeNode* root)
    {
        ans+=to_string(root->val);

        if (root->left!=NULL)
        {
            ans+="(";
            func(root->left);
            ans+=")";
        }
        else if (root->right){ans+="()";}
        if (root->right!=NULL)
        {
            ans+="(";
            func(root->right);
            ans+=")";
        }
    }

    string tree2str(TreeNode* root) {
        if (root == NULL){return "";}
        func(root);
        return ans;

    }
};