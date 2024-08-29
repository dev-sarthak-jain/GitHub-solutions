class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& arr, vector<int>& nums, int n, int x)
    {
        ans.push_back(arr);
        for(int i=x;i<n;i++)
        {
            arr.push_back(nums[i]);
            func(ans,arr,nums,n,i+1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        func(ans,arr,nums,nums.size(), 0);
        return ans;
    }
};