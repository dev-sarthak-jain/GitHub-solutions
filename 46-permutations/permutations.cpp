class Solution {
public:
    
    void func(vector<vector<int>>& ans, vector<bool>& check, vector<int>& nums,vector<int>& arr, int n)
    {
        if (arr.size() == n){ans.push_back(arr);return;}
        for(int i=0;i<n;i++)
        {
            int temp = nums[i]+10;
            if (check[temp]==0){
                check[temp] = 1;
                arr.push_back(nums[i]);
                func(ans,check,nums,arr, n);
                arr.pop_back();
                check[temp] = 0;
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> check (21,0);
        vector<vector<int>> ans;
        vector<int> arr;
        func(ans,check,nums,arr,nums.size());
        return ans;
    }
};