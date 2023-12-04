class Solution {
public:
    string largestGoodInteger(string nums) {
        int n = nums.length();
        string ans = "";
        for(int i=1;i<n;i++)
        {
            if (i+1<n && nums[i] == nums[i-1] && nums[i] == nums[i+1])
            {
                if (ans == "")
                {
                    ans = nums[i];
                }
                else if (ans[0] < nums[i])
                {
                    ans = nums[i];
                }
            }
        }
        return ans + ans + ans;
    }
};