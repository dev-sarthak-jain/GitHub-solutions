class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++)
        {
            int j=0,k=i-1;
            while(j<k)
            {
                dp[i] += 2*dp[j]*dp[k];
                j++;k--;
            }
            if (j==k)
            {
                dp[i] += dp[j]*dp[k];
            }
        }
        return dp[n];
    }
};