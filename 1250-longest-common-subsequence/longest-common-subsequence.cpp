class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length(), m = t2.length();
        vector<vector<int>> vec(n,vector<int>(m));
        if (t1[0] == t2[0]){vec[0][0] = 1;}
        for(int i=1;i<n;i++)
        {
            if (t1[i] == t2[0]){vec[i][0] = 1;}
            else{vec[i][0] = vec[i-1][0];}
        }
        for(int i=1;i<m;i++)
        {
            if (t1[0] == t2[i]){vec[0][i] = 1;}
            else{vec[0][i] = vec[0][i-1];}
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if (t1[i] == t2[j])
                {
                    vec[i][j] = vec[i-1][j-1] + 1;
                }
                else
                {
                    vec[i][j] = max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        */
        return vec[n-1][m-1];
    }
};