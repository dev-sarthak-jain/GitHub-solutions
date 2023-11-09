class Solution {
public:
    unordered_map<int,int> map;
    void recur(TreeNode* root)
    {
        if (root == NULL){return;}
        map[root->val]++;
        recur(root->left);
        recur(root->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        recur(root);
        vector<int> ans;
        int m = 0;
        for (auto x : map) {
            m = max(m, x.second);
        }
        for(auto x : map)
        {
            if (x.second == m){ans.push_back(x.first);}
        }
        return ans;
    }
};