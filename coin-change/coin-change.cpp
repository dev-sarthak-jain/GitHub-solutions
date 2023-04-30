class Solution {
public:
    int *dp;
    int recur(vector<int>&coins, int amount)
    {
        if (amount == 0){return 0;}
        if (amount<0){return INT_MAX;}
        if (dp[amount] != -1){return dp[amount];}
        int m = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            m = min(recur(coins,amount - coins[i]),m);
        }
        if (m!=INT_MAX){m++;}
        dp[amount] = m;
        return m;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp = new int[amount+1];
        for(int i=0;i<amount+1;i++)
        {
            dp[i] = -1;
        }
        int ans =  recur(coins,amount);
        delete [] dp;
        if (ans == INT_MAX){return -1;}
        return ans;
    }
};