class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        vector<int> temp(n,1);

        for(int i = 1;i<n;i++)
        {
            if (nums[i] > nums[i-1])
            {
                temp[i] = temp[i-1]+1;
            }
        }
        for(int i = n-2;i>=0;i--)
        {
            if (nums[i] > nums[i+1])
            {
                temp[i] = max(temp[i] , temp[i+1]+1);
            }
        }
        return accumulate(temp.begin(), temp.end(), 0);

    }
};