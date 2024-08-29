class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& candidates,vector<int>& arr, int target,int n, int x, int curr)
    {
        if (curr==target){ans.push_back(arr);}
        if (curr>target){return;}
        vector<bool> check (51,0);
        for(int i=x;i<n;i++)
        {
            if (check[candidates[i]] == 1){continue;}
            check[candidates[i]] = 1;
            arr.push_back(candidates[i]);
            curr += candidates[i]; 
            func(ans,candidates,arr,target,n,i+1,curr);
            arr.pop_back();
            curr -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        func(ans,candidates,arr,target,candidates.size(),0,0);
        return ans;
    }
};