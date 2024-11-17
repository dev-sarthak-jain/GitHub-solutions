class Solution {
public:
    int n,m;
    int func(vector<vector<int>>& vec, string& text1, string& text2, int x,int y)
    {
        if (x>=n || y>=m){return 0;}
        else if (vec[x][y]!=-1){return vec[x][y];}
        else if (text1[x] == text2[y]){vec[x][y] = 1 + func(vec,text1,text2,x+1,y+1);}
        else {vec[x][y] = max(func(vec,text1,text2,x+1,y),func(vec,text1,text2,x,y+1));}
        return vec[x][y];
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        vector<vector<int>> vec(n,vector<int>(m,-1));
        return func(vec,text1,text2,0,0);
    }
};