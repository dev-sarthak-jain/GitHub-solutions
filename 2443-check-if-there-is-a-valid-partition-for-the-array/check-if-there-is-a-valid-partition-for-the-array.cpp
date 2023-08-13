class Solution {
public:
    int n;
    bool recur(vector<int>& nums, vector<int>& check, int x)
    {
        if (x==n){return true;}
        if (check[x] != -1){return check[x];}
        if (x+1<n && nums[x] == nums[x+1])
        {
            if (recur(nums,check,x+2)){check[x] = 1;return 1;}
            if (x+2<n && nums[x] == nums[x+2])
            {
                if (recur(nums,check,x+3)){check[x] = 1;return 1;}
            }
        }
        if (x+2<n && nums[x]+1 == nums[x+1] && nums[x]+2 == nums[x+2])
        {
            if (recur(nums,check,x+3)){cout << x << endl; check[x] = 1;return 1;}
        }
        check[x] = 0;
        return 0;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        vector<int> check(n,-1);
        return recur(nums,check,0);
    }
};