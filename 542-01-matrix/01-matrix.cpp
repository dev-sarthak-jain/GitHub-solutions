class Solution {
public:

    vector<vector<int>> list = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vec(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push(make_pair(i,j));
                    vec[i][j] = 0;
                }
            }
        }

        while(q.size()!=0)
        {
            pair<int,int> current = q.front();
            q.pop();
            int x = current.first, y = current.second;
            for(int i=0;i<4;i++)
            {
                int a = x + list[i][0];
                int b = y + list[i][1];
                if (a >= 0 && a < n && b >= 0 && b < m && vec[a][b]==INT_MAX)
                {
                    q.push(make_pair(a,b));
                    vec[a][b] = vec[x][y] + 1;
                }
            }
        }

        return vec;
    }
};