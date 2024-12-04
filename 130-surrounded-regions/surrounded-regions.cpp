class Solution {
public:
    int n,m;
    void BFS(vector<vector<char>>& board, int i, int j)
    {
        queue<pair<int,int>> s;
        s.push({i,j});
        vector<pair<int,int>> rec;
        while(!s.empty())
        {
            pair<int,int> p = s.front();
            s.pop();
            int x = p.first, y = p.second;
            if (x<0 || x>=n || y<0 || y>=m || board[x][y] == 'X' ||  board[x][y] == '#'){continue;}
            board[x][y] = '#';
            s.push({x+1,y});
            s.push({x-1,y});
            s.push({x,y+1});
            s.push({x,y-1});
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i=0;i<n;i++)
        {
            if (board[i][0] == 'O'){BFS(board,i,0);}
            if (board[i][m-1] == 'O'){BFS(board,i,m-1);}
        }
        for (int i=0;i<m;i++)
        {
            if (board[0][i] == 'O'){BFS(board,0,i);}
            if (board[n-1][i] == 'O'){BFS(board,n-1,i);}
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j] == 'O'){board[i][j] = 'X';}
                if (board[i][j] == '#'){board[i][j] = 'O';}
            }
        }
    }
};

/*
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
*/