class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() && nums[i] <= 0) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    l++;
                    continue;
                }
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                }
                else if (sum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
            i++;
        }
        return ans;
    }
};