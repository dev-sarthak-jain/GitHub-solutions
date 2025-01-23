class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;

    int func(vector<vector<int>>& coins, int x, int y, int k)
    {
        if (x>=n || y>=m){return INT_MIN;}
        if (x==n-1 && y == m-1){
            if (k>0 && coins[x][y]<0){return 0;}
            return coins[x][y];
        }
        if (dp[x][y][k]!=INT_MIN){return dp[x][y][k];}

        int pathMax = INT_MIN;

        if (x+1<n) pathMax = max(pathMax, coins[x][y] + func(coins,x+1,y,k));
        if (y+1<m) pathMax = max(pathMax, coins[x][y] + func(coins,x,y+1,k));
        if (coins[x][y]<0 && k >0)
        {
            if (x+1<n) pathMax = max(pathMax, func(coins,x+1,y,k-1));
            if (y+1<m) pathMax = max(pathMax, func(coins,x,y+1,k-1));
        }
        return dp[x][y][k] = pathMax;

    }


    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return func(coins,0,0,2);
    }
};