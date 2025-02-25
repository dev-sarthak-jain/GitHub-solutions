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

    TreeNode* func(vector<int>& pre, vector<int>& in, int a, int b, int x, int y)
    {
        if (x>y){return NULL;}
        TreeNode* temp = new TreeNode(pre[a]);
        int mid;
        for(int i=x;i<=y;i++)
        {
            if (in[i]==pre[a]){mid = i; break;}
        }

        int to = a+(mid-x);

        temp->left = func(pre,in,a+1,to,x,mid-1);
        temp->right = func(pre,in,to+1,b,mid+1,y);
        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return func(preorder,inorder,0,n-1,0,n-1);
    }
};