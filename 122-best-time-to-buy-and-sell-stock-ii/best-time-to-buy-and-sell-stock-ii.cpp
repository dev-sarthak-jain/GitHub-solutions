class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0;
        int j=1, n = nums.size();
        while(j<n)
        {
            if (nums[j] > nums[j-1])
            {
                profit += nums[j] - nums[j-1];
            }
            j++;
        }
        return profit;
    }
};