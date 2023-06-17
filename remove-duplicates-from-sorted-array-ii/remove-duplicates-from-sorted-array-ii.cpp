class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1,j=1;
        while(j<n)
        {
            if (nums[j] == nums[j-1])
            {
                nums[i] = nums[j];
                j++;
                i++;
                while(j<n && nums[j] == nums[j-1])
                {
                    j++;
                }
                if (j==n){break;}
            }
            nums[i] = nums[j];
            i++;j++;
        }
        return i;
    }
};