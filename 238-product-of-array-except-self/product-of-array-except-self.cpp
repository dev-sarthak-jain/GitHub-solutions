class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int> ans(n,1);
        int suffix = 1;
        for(int i=1;i<n;i++)
        {
            ans[i] = nums[i-1] * ans[i-1];
        }
        for(int i=0; i<n ;i++)
        {
            ans[n-i-1]*=suffix;
            suffix = nums[n-i-1]*suffix;
        }
        return ans;
    }
};