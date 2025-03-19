class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n-2;i++)
        {
            if (nums[i]==0)
            {
                ans++;
                nums[i+1] = nums[i+1]==1?0:1;
                nums[i+2] = nums[i+2]==1?0:1;
            }
        }
        if (!nums[n-1] || !nums[n-2]){return -1;}
        else{return ans;}
    }
};