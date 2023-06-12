class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){return {};}
        vector<string> ans;
        int i = 0,j = 1;
        while(j<n)
        {
            if (nums[j]!=nums[j-1]+1)
            {
                if (i == j-1)
                {
                    ans.push_back(to_string(nums[i]));
                }
                else
                {
                    ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
                }
                i=j;
            }
            j++;
        }
        if (i == j-1)
        {

            ans.push_back(to_string(nums[i]));        }
        else
        {
            ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        }
        return ans;
    }
};