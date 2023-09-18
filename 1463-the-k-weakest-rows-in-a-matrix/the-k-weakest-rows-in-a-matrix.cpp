class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        int m = nums[0].size();
        vector<pair<int, int>> rows;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            rows.push_back({count, i});
        }
        sort(rows.begin(), rows.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(rows[i].second);
        }
        
        return ans;
    }
};
