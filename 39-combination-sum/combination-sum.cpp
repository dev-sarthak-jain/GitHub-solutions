class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& candidates,vector<int>& arr, int target,int n, int x, int curr)
    {
        if (curr==target){ans.push_back(arr);}
        if (curr>target){return;}

        for(int i=x;i<n;i++)
        {
            arr.push_back(candidates[i]);
            curr += candidates[i]; 
            func(ans,candidates,arr,target,n,i,curr);
            arr.pop_back();
            curr -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        func(ans,candidates,arr,target,candidates.size(),0,0);
        return ans;
    }
};