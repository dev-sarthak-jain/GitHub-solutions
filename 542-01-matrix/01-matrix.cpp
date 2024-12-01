class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> que;
        int zero = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> check(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if (!mat[i][j])
                {
                    que.push({{i,j},0});
                    check[i][j] = 1;
                }
                else
                {
                    zero++;
                }
            }
        }

        while(zero && !que.empty())
        {
            auto node = que.front();
            que.pop();
            int x = node.first.first, y = node.first.second, level = node.second;
            if (x+1<n && !check[x+1][y]){zero--;check[x+1][y] = 1; mat[x+1][y] = level+1; que.push({{x+1,y},level+1});}
            if (x-1>=0 && !check[x-1][y]){zero--;check[x-1][y] = 1; mat[x-1][y] = level+1; que.push({{x-1,y},level+1});}
            if (y+1<m && !check[x][y+1]){zero--;check[x][y+1] = 1; mat[x][y+1] = level+1; que.push({{x,y+1},level+1});}
            if (y-1>=0 && !check[x][y-1]){zero--;check[x][y-1] = 1; mat[x][y-1] = level+1; que.push({{x,y-1},level+1});}
        }
        
        return mat;
    }
};