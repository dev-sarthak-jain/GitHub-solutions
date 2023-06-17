class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0, j = nums.size()-1,m = 0;
        while(i<j)
        {   
            if (nums[i]<nums[j])
            {
                m = max(m,(nums[i] * (j-i)));
                i++;
            }
            else
            {
                m = max(m,(nums[j] * (j-i)));
                j--;
            }
        }
        return m;
    }
};