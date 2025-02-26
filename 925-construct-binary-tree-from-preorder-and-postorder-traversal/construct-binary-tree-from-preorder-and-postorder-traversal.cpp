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
    unordered_map<int,int> map1;
    unordered_map<int,int> map2;
    int preCount = 0;
    TreeNode* func(vector<int>& pre, vector<int>& post, int x, int y)
    {
        if (x>y){return NULL;}
        TreeNode* root = new TreeNode(pre[preCount++]);
        if (x==y){return root;}
        int left = pre[preCount];
        int split = map2[left];
        root->left = func(pre,post,x,split);
        root->right = func(pre,post,split+1,y-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i=0;i<n;i++)
        {
            map1[pre[i]] = i;
            map2[post[i]] = i;
        }
        return func(pre,post,0,n-1);
    }
};