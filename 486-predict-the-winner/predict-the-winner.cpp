class Solution {
public:

    int recur(vector<int>& nums, vector<vector<int>>& vec, int l, int r)
    {
        if (vec[l][r]!=-1){return vec[l][r];}

        if (l==r){return nums[l];}

        int left = nums[l] - recur(nums,vec,l+1,r);
        int right = nums[r] - recur(nums,vec,l,r-1);
        vec[l][r] = max(left,right);

        return vec[l][r];
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec(n,vector<int>(n,-1));
        return recur(nums,vec,0,n-1)>=0;
    }
};