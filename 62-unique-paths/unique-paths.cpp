class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            vec[i][m-1] = 1;
        }
        for(int i=0;i<m;i++)
        {
            vec[n-1][i] = 1;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                vec[i][j] = vec[i+1][j] + vec[i][j+1];
            }
        }
        return vec[0][0];

    }
};