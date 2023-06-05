class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        int n = nums.size();
        int x = nums[0][0];
        int y = nums[0][1];
        int denom = nums[1][0] - x;
        
        if (denom == 0) {
            for (int i = 2; i < n; i++) {
                if (x - nums[i][0] != 0) {
                    return false;
                }
            }
            return true;
        } else {
            for (int i = 2; i < n; i++) {
                if (static_cast<double>(nums[i][1] - y) / (nums[i][0] - x) != static_cast<double>(nums[1][1] - y) / denom) {
                    return false;
                }
            }
            return true;
        }
    }
};
