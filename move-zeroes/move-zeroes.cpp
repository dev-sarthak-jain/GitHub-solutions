class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        
        int c = 0,x=j;
        while(j<n)
        {
            if (nums[j] != 0)
            {
                nums[x] = nums[j];
                x++;
            }
            else
            {
                c++;
            }
            j++;
        }
        j = n-c;
        while(j<n)
        {
            nums[j] = 0;
            j++;
        }
    }
};
