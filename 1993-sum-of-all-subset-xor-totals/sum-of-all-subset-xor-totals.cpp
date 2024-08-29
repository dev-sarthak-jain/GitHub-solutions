class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& nums, int& XORtotal, int total, int n, int x)
    {
        XORtotal += total;
        for(int i=x;i<n;i++)
        {
            total ^= nums[i];
            func(ans,nums,XORtotal,total,n,i+1);
            total ^= nums[i];
        }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int XORtotal = 0;
        func(ans,nums,XORtotal,0,nums.size(), 0);
        return XORtotal;
    }
};