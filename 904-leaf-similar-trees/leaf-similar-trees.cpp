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
    void LeafValueGenerator(TreeNode* root,vector<int>& check)
    {
        if (root->left == NULL && root->right == NULL){check.push_back(root->val);return;}
        if (root->left != NULL){LeafValueGenerator(root->left,check);}
        if (root->right != NULL){LeafValueGenerator(root->right,check);}
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        LeafValueGenerator(root1,arr1);
        LeafValueGenerator(root2,arr2);
        if (arr1.size()!=arr2.size()){return false;}
        for(int i=0;i<arr1.size();i++)
        {
            if (arr1[i]!=arr2[i]){return false;}
        }
        return true;
    }
};