class Solution {
public:
    void func(vector<vector<int>>& ans, vector<bool>& check,vector<int>& arr,vector<int>& nums, int n, int x)
    {
        if (n==x){ans.push_back(arr);return;}
        for(int i=0;i<n;i++)
        {
            if (check[i]){continue;}
            if (i!=0 && nums[i]==nums[i-1] && !check[i-1]){continue;}
            check[i] = 1;
            arr.push_back(nums[i]);
            func(ans,check,arr,nums,n,x+1);
            arr.pop_back();
            check[i] = 0;
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> check (nums.size(),0);
        sort(nums.begin(),nums.end());
        vector<int> arr;
        func(ans,check,arr,nums,nums.size(),0);
        return ans;
    }
};