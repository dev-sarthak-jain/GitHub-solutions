class Solution {
public:
    int m,n;

    int helper(vector<vector<int>>& grid, vector<vector<bool>>& check, int x, int y)
    {
        if (x>=0 && x<n && y>=0 && y<m)
        {
            if (grid[x][y] == 0 || check[x][y] == 1){return 0;}
            check[x][y] = 1;
            
            return 1 + helper(grid,check,x+1,y) + helper(grid,check,x,y+1) + helper(grid,check,x-1,y) + helper(grid,check,x,y-1);
        }
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> check (n, vector<bool> (m,0));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (check[i][j]==0 && grid[i][j])
                {
                    ans = max(ans,helper(grid,check,i,j));
                }
            }
        }
        return ans;
    }
};