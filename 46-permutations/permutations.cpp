class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> temp;

    void recur(vector<int>& nums, bool check[], int  x)
    {
        if (x==n){ans.push_back(temp);return;}

        for(int i=0;i<n;i++)
        {
            if (check[i]!=1)
            {
                temp.push_back(nums[i]);
                check[i] = 1;
                recur(nums,check,x+1);
                check[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        bool check[n];
        recur(nums,check,0);
        return ans;
    }
};