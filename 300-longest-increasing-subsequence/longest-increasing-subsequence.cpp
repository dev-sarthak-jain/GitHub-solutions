class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,1);
        int max_ans = 1;
        for(int i=1;i<n;i++)
        {
            int ans = 1;
            for(int j=i-1;j>=0;j--)
            {
                if (nums[j]<nums[i])
                {
                    ans = max(vec[j]+1,ans);
                    if (ans > max_ans){
                        break;
                    }
                }
            }
            vec[i] = ans;
            max_ans = max(max_ans,vec[i]);
        }
        return max_ans;
    }
};