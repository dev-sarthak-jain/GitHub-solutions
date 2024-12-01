class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n,vector<bool>(m,0));
        int island = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (grid[i][j]-'0' && !check[i][j])
                {
                    island++;
                    stack<vector<int>> s;
                    s.push({i,j});
                    while(!s.empty())
                    {
                        vector<int> tuple = s.top();
                        s.pop();
                        int x = tuple[0], y = tuple[1];
                        check[x][y] = 1;
                        if (x-1>=0 && grid[x-1][y]-'0' &&!check[x-1][y]){s.push({x-1,y});}
                        if (y-1>=0 && grid[x][y-1]-'0' && !check[x][y-1]){s.push({x,y-1});}
                        if (x+1<n && grid[x+1][y]-'0' && !check[x+1][y]){s.push({x+1,y});}
                        if (y+1<m && grid[x][y+1]-'0' && !check[x][y+1]){s.push({x,y+1});}
                    }
                }
            }
        }
        return island;
    }
};