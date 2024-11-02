class Solution {
public:
    int n;
    int func(vector<int>& coins, vector<int>& check, int amount)
    {
        if (amount < 0){return INT_MAX;}
        if (check[amount]<INT_MAX){return check[amount];}
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int res = func(coins,check,amount-coins[i]);
            if (res==-1){continue;}
            ans = min(ans,res);
        }
        if (ans == -1){check[amount] = -1;return -1;}
        if (ans == INT_MAX){ans = -1;check[amount] = ans;return ans;}
        check[amount] = ans+1;
        return ans+1;

    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> check(amount+1, INT_MAX);
        check[0] = 0;
        n = coins.size();
        int ans = func(coins,check,amount);
        return ans;
    }
};