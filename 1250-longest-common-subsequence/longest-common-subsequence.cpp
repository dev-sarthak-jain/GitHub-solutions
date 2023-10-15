class Solution {
public:
    string s1,s2;
    int n,m;
    int recur(vector<vector<int>>& vec, int x,int y)
    {
        if (x==n || y==m){return 0;}
        if (vec[x][y]!=-1){return vec[x][y];}
        if (s1[x] == s2[y]){
            vec[x][y] = recur(vec,x+1,y+1) + 1;
            return vec[x][y];
        }
        else
        {
            vec[x][y] = max(recur(vec,x+1,y),recur(vec,x,y+1));
            return vec[x][y];
        }
    }

    int longestCommonSubsequence(string t1, string t2) {
        s1 = t1;
        s2 = t2;
        n = s1.length();
        m = s2.length();
        vector<vector<int>> vec(n,vector<int>(m,-1));
        return recur(vec,0,0);
    }
};