class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        dp[0][0][0] = coins[0][0];
        if (coins[0][0]<0)
        {
            dp[0][0][1] = 0;
        }
        for(int k=0;k<3;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    if (dp[i][j][k]==INT_MIN){continue;}
                    if (i+1<n){dp[i+1][j][k] = max(dp[i][j][k] + coins[i+1][j], dp[i+1][j][k]);}
                    if (j+1<m){dp[i][j+1][k] = max(dp[i][j][k] + coins[i][j+1], dp[i][j+1][k]);}
                    if (i+1<n && coins[i+1][j]<0 && k<2){dp[i+1][j][k+1] = max(dp[i][j][k],dp[i+1][j][k+1]);}
                    if (j+1<m && coins[i][j+1]<0 && k<2){dp[i][j+1][k+1] = max(dp[i][j][k],dp[i][j+1][k+1]);}
                }
            }
        }
        /*
        for(int k=0;k<3;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    cout << dp[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl << endl;
        }
        */
        return max(dp[n-1][m-1][0], max(dp[n-1][m-1][1],dp[n-1][m-1][2]));

    }
};