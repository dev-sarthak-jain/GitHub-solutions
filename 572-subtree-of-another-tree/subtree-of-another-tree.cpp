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
    bool check(TreeNode* root, TreeNode* sub)
    {
        bool a = (root==NULL), b = (sub == NULL);
        if ((!a & b) || (a && !b)){return false;}
        else if (a && b){return true;}
        else if (!a && !b && root->val == sub->val){return (check(root->left,sub->left) && check(root->right,sub->right));}
        else{return false;}
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()!=0)
        {
            TreeNode* temp = que.front();
            que.pop();
            if (temp->val == sub->val && check(temp, sub)){cout << "F" << endl;return true;}
            if (temp->left != NULL){que.push(temp->left);}
            if (temp->right != NULL){que.push(temp->right);}
        }
        return false;
    }
};