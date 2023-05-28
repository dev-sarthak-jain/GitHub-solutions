class Solution {
public:
    int a, b;

    int recur(vector<vector<int>>& target,int x,int y)
    {
        if (x>a-1 || y>b-1){return 0;}
        if (target[x][y]!=-1){return target[x][y];}
        int ans = 0;
        if (x+1<a){ans+=recur(target,x+1,y);}
        if (y+1<b){ans+=recur(target,x,y+1);}
        target[x][y] = ans;
        return ans;
    }

    int uniquePaths(int m, int n) {
        a = m;
        b = n;
        vector<vector<int>> target(m,vector<int>(n,-1));
        target[m-1][n-1] = 1;
        return recur(target,0,0);
    }
};