class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool check(int x,int y,vector<string>& s)
    {
        for(int i=0;i<n;i++)
        {
            if (s[i][y] == 'Q'){return 0;}
        }
        for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
            if (s[i][j] == 'Q'){return 0;}
        }
        for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++){
            if (s[i][j] == 'Q'){return 0;}
        }
        return 1;
    }

    void recur(int a, vector<string>& s)
    {
        if (a==n){ans.push_back(s);}

        for(int i=0;i<n; i++)
        {
            if (check(a,i,s))
            {
                s[a][i] = 'Q';
                recur(a+1,s);
                s[a][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int m) {
        string s(m,'.');
        vector<string> temp(m,s);
        n = m;
        recur(0,temp);
        return ans;
    }
};