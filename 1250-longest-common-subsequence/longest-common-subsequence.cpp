class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length(), m = t2.length();
        vector<vector<int>> vec (n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (t1[i] == t2[j])
                {
                    vec[i+1][j+1] = vec[i][j] + 1;
                }
                else
                {
                    vec[i+1][j+1] = max(vec[i][j+1],vec[i+1][j]);
                }
            }
        }
        return vec[n][m];
    }
};