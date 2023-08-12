class Solution {
public:
    int n,m;

    int recur(vector<vector<int>>& grid,vector<vector<int>>& vec,int x, int y)
    {
        if (x>=n || y>=m){return 0;}

        if (vec[x][y]!=-1){return vec[x][y];}

        if (grid[x][y]){return 0;}

        vec[x][y] = recur(grid,vec,x+1,y) + recur(grid,vec,x,y+1);
        return vec[x][y];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (grid[n-1][m-1]){return 0;}
        vector<vector<int>> vec(n,vector<int>(m,-1));
        vec[n-1][m-1] = 1;
        return recur(grid,vec,0,0);
    }
};