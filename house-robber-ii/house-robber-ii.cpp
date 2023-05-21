class Solution {
public:

    int func(vector<int>& nums,int x,int y)
    {
        int n = y-x+1;
        int dp[n];
        int p = 0, q = nums[x],r;
        for(int i=1;i<n;i++)
        {
            r = max(q,p + nums[i+x]);
            p = q;
            q = r;
        }
        return r;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){return nums[0];}
        return max(func(nums,0,n-2),func(nums,1,n-1));
    }
};