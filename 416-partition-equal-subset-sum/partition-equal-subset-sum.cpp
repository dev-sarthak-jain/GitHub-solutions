class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum%2==1){return false;}
        total_sum = total_sum/2;
        vector<bool> vec(total_sum+1,0);
        vec[0] = 1;
        for (int i=0;i<n;i++)
        {
            for(int j=total_sum;j>=nums[i];j--)
            {
                vec[j] = vec[j] || vec[j - nums[i]];
            }
        }
        return vec[total_sum];
    }
};