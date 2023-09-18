class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n;
    void recur(vector<int>& nums,vector<bool>& check, int x)
    {
        if (x==n){ans.push_back(temp);}

        for(int i=0;i<n;i++)
        {
            if (check[i] != 1)
            {
                check[i] = 1;
                temp.push_back(nums[i]);
                recur(nums,check,x+1);
                temp.pop_back();
                check[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> check(n,0);
        recur(nums,check,0);
        return ans;
    }
};