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
    bool recur(TreeNode* root, int target)
    {
        if (root==NULL){return 1;}
        cout << root->val << endl;
        bool check1 = recur(root->left, target);
        bool check2 = recur(root->right, target);
        if (check1 && check2)
        {
            root->left = NULL;
            root->right = NULL;
            if (root->val == target){return 1;}
            else {return 0;}
        }
        else if (check1)
        {
            root->left = NULL;
        }
        else if (check2)
        {
            root->right = NULL;
        }
        else
        {return 0;}
        return 0;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (recur(root,target)){return NULL;}
        return root;
    }
};