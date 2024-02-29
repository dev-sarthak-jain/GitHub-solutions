class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool flag = 0;
        while(que.size()!=0)
        {
            int n = que.size();
            if (flag == 0)
            {
                TreeNode* prev = que.front(),*temp;
                que.pop();
                if (prev->val%2==0){return false;}
                if (prev->left){que.push(prev->left);}
                if (prev->right){que.push(prev->right);}
                for(int i=1;i<n;i++)
                {
                    temp = que.front();
                    que.pop();
                    if (temp->val%2==0 || temp->val <= prev->val){return false;}
                    if (temp->left){que.push(temp->left);}
                    if (temp->right){que.push(temp->right);}
                    prev = temp;
                }
            }
            else
            {
                TreeNode* prev = que.front(),*temp;
                que.pop();
                if (prev->val%2==1){return false;}
                if (prev->left){que.push(prev->left);}
                if (prev->right){que.push(prev->right);}
                for(int i=1;i<n;i++)
                {
                    temp = que.front();
                    que.pop();
                    if (temp->val%2==1 || temp->val >= prev->val){return false;}
                    if (temp->left){que.push(temp->left);}
                    if (temp->right){que.push(temp->right);}
                    prev = temp;
                }
            }
            flag = !flag;
        }
        return true;
    }
};