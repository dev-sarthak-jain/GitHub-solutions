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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL){return root;}
        else{root->val = 0;}
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(que.size()!=0)
        {
            int sum = 0;
            queue<TreeNode*> que2;
            while(que.size()!=0)
            {
                TreeNode* temp = que.front();
                que.pop();
                if (temp!=NULL)
                {
                    sum+=temp->val;
                }
                que2.push(temp);
            }
            if (sum == 0){break;}
            while(que2.size()!=0)
            {
                TreeNode* temp1 = que2.front();
                que2.pop();
                TreeNode* temp2 = que2.front();
                que2.pop();
                int a=0,b=0;
                if (temp1!=NULL){a = temp1->val;}
                if (temp2!=NULL){b = temp2->val;}
                if (temp1!=NULL){temp1->val = sum - a - b;que.push(temp1->left);que.push(temp1->right);}
                if (temp2!=NULL){temp2->val = sum - a - b;que.push(temp2->left);que.push(temp2->right);}
            }
        }
        return root;
    }
};