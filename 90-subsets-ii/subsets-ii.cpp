class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& arr, vector<int>& nums, int n, int x)
    {
        ans.push_back(arr);
        vector<bool> check (21,0);
        for(int i=x;i<n;i++)
        {
            if (check[nums[i]+10]==1){continue;}
            arr.push_back(nums[i]);
            check[nums[i]+10]=1;
            func(ans,arr,nums,n,i+1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> arr;
        vector<bool> check (21,0);
        func(ans,arr,nums,nums.size(), 0);
        return ans;
    }
};