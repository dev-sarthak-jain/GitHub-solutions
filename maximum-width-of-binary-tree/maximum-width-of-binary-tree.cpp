class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,long int>> que;
       if (root->left!=NULL){que.push({root->left,1});}
       if (root->right!=NULL){que.push({root->right,2});}
       long int m = 1;
       while(que.size())
       {
            int n = que.size();
            TreeNode *temp;
            long int rev;
            m = max(que.back().second - que.front().second + 1,m);
            long int x = que.front().second;
            for(int i=0;i<n;i++)
            {
                temp = que.front().first;
                rev = que.front().second - x;
                if (temp->left!=NULL){que.push({temp->left,(rev*2) - 1});}
                if (temp->right!=NULL){que.push({temp->right,(rev*2)});}
                que.pop();
            }
       }
       return m;
    }
};