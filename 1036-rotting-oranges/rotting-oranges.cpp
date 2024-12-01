class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> s;
        int n = grid.size();
        int m = grid[0].size();
        int orange = 0;
        for(int i=0; i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (grid[i][j] == 2)
                {
                    s.push({{i,j},0});
                }
                else if (grid[i][j] == 1)
                {
                    orange++;
                }
            }
        }

        int count = 0;
        while(!s.empty())
        {
            pair<pair<int,int>,int> p = s.front();
            s.pop();
            int x = p.first.first, y = p.first.second, level = p.second;
            if (x+1<n && grid[x+1][y]==1){orange--;grid[x+1][y]=2;s.push({{x+1,y},level+1});}
            if (x-1>=0 && grid[x-1][y]==1){orange--;grid[x-1][y]=2;s.push({{x-1,y},level+1});}
            if (y+1<m && grid[x][y+1]==1){orange--;grid[x][y+1]=2;s.push({{x,y+1},level+1});}
            if (y-1>=0 && grid[x][y-1]==1){orange--;grid[x][y-1]=2;s.push({{x,y-1},level+1});}
            count = max(count,level);
        }
        if (!orange)return count;
        else return -1;
    }
};