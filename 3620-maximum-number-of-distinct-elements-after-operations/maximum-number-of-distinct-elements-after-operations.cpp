class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1){return 1;}
        sort(nums.begin(),nums.end());
        int last = nums[0] - k;
        int count = 1;
        for(int i=1;i<n;i++)
        {
            int val = max(last+1,nums[i]-k);
            if (val<nums[i]+k+1){count++;last = val;}
        }
        return count;
    }
};