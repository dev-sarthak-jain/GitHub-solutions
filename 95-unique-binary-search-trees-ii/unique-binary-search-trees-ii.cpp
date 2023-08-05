class Solution {
public:
    vector<TreeNode*> recur(int x,int y)
    {
        if (x>y){return {nullptr};}
        vector<TreeNode*> ans;
        for(int i=x;i<y+1;i++)
        {
            vector<TreeNode*> a = recur(x,i-1);
            vector<TreeNode*> b = recur(i+1,y);
            for(int j=0;j<a.size();j++)
            {
                for(int k=0;k<b.size();k++)
                {
                    TreeNode* temp = new TreeNode(i,a[j],b[k]); 
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return recur(1,n);
    }
};