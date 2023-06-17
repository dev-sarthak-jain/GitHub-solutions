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
    unordered_map<int,int> map;
    TreeNode* recur(vector<int>& pre, vector<int>& in, int ps,int pe, int is, int ie)
    {
        if (ps>pe ){return NULL;}
        TreeNode* root = new TreeNode(pre[ps]);
        int i = map[root->val];
        int z = i-is;
        root->left = recur(pre,in,ps+1,ps+z,is,i-1);
        root->right = recur(pre,in,ps+z+1,pe,i+1,ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++)
        {
            map[inorder[i]] = i;
        }
        return recur(preorder, inorder, 0,n-1,0,n-1);
    }
};