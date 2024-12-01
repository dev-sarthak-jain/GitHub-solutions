class Solution {
public:
    void recur(vector<vector<int>> & nums, vector<bool> & check, int n,int x)
    {
        for(int i=0;i<n;i++)
        {
            if (nums[x][i] && !check[i])
            {
                check[i] = 1;
                recur(nums,check,n,i);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<bool> check(n,0);
        int prov = 0;
        for(int i=0;i<n;i++)
        {
            if (check[i]==0)
            {
                check[i] = 1;
                recur(nums,check,n,i);
                prov++;
            }
        }
        return prov;
    }
};