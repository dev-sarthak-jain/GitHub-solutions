class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> check(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (!check[i][j] && board[i][j] == 'O')
                {
                    queue<pair<int,int>> s;
                    s.push({i,j});
                    vector<pair<int,int>> rec;
                    bool edge = false;
                    while(!s.empty())
                    {
                        pair<int,int> p = s.front();
                        s.pop();
                        int x = p.first, y = p.second;
                        if (x<0 || x>=n || y<0 || y>=m){edge = 1;continue;}
                        if (board[x][y] == 'X' || check[x][y]){continue;}
                        rec.push_back({x,y});
                        check[x][y] = 1;
                        s.push({x+1,y});
                        s.push({x-1,y});
                        s.push({x,y+1});
                        s.push({x,y-1});
                    }
                    if (!edge)
                    {
                        for(int k=0;k<rec.size();k++)
                        {
                            board[rec[k].first][rec[k].second] = 'X';
                        }
                    }
                }
            }
        }
        return ;
    }
};