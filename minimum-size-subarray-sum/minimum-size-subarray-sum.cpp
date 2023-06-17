class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,m = INT_MAX,n = nums.size(),sum = 0;
        while(j<n)
        {
            sum+=nums[j];
            j++;
            if (sum >= target)
            {
                while(sum-nums[i]>=target)
                {
                    sum-=nums[i];
                    i++;
                }
                m = min(m,j-i);
                sum -= nums[i];
                i++;
            }
        }
        return (m == INT_MAX) ? 0:m;
    }
};