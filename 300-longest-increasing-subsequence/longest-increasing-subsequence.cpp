class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,1);
        int max_ans = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if (nums[j]<nums[i])
                {
                    vec[i] = max(vec[j]+1,vec[i]);
                    if (vec[i] > max_ans){
                        break;
                    }
                }
            }
            max_ans = max(max_ans,vec[i]);
        }
        return max_ans;
    }
};