class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n);
        int i=0,j=0,k=0;
        while(i<n && nums[i]<0)
        {
            i++;
        }
        j = i-1;
        while(j>=0 && i<n)
        {
            if (-1*nums[j]>nums[i])
            {
                ans[k] = nums[i]*nums[i];
                i++;
            }
            else
            {
                ans[k] = nums[j]*nums[j];
                j--;
            }
            k++;
        }
        while(j>=0)
        {
            ans[k] = nums[j]*nums[j];
            k++;j--;
        }
        while(i<n)
        {
            ans[k] = nums[i]*nums[i];
            k++;i++;
        }
        return ans;

    }
};