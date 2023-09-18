class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
        vector<pair<int,int>> vec;
        vector<int> ans;
        int n = nums.size(), m = nums[0].size();
        for(int i=0; i<n; i++)
        {
            vec.push_back({m,i});
            for(int j=0; j<m; j++)
            {
                if (nums[i][j] == 0)
                {
                    vec[i] = {j,i};
                    break;
                }
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};