class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if (old == color){return image;}
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> que;
        que.push(make_pair(sr,sc));
        while(que.size()!=0)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            image[x][y] = color;
            if (x+1<n && image[x+1][y] == old){que.push(make_pair(x+1,y));}
            if (x-1>=0 && image[x-1][y] == old){que.push(make_pair(x-1,y));}
            if (y+1<m && image[x][y+1] == old){que.push(make_pair(x,y+1));}
            if (y-1>=0 && image[x][y-1] == old){que.push(make_pair(x,y-1));}

        }
        return image;
    }
};