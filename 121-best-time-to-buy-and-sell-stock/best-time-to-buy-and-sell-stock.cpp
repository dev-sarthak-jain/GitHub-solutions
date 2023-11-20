class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int i=0,j=1,m=0;
        int n = nums.size();
        while(j<n)
        {
            if (nums[j]<nums[i])
            {
                i = j;
            }
            else{
                m = max(nums[j]-nums[i],m);
            }
            j++;
        }
        return m;
    }
};