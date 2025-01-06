class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> vec(n,0);
        long sum = 0;
        for(int i=0;i<n;i++)
        {
            vec[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            sum += nums[i];
            vec[i] -= sum;
        }
        int total = 0;
        for(int i=1;i<n;i++)
        {
            if (vec[i]>=0)
            {
                total++;
            }
        }
        return total;
    }
};