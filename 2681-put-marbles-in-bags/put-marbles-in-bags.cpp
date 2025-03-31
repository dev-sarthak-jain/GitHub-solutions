class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> splits(n-1);
        for(int i=0;i<n-1;i++)
        {
            splits[i] = nums[i] + nums[i+1];
        }
        long long int score = 0;
        sort(splits.begin(),splits.end());
        for(int i=0;i<k-1;i++)
        {
            score = score - splits[i] + splits[n-2-i];
        }
        return score;
    }
};