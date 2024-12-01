class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ele = image[sr][sc];
        if (ele == color){return image;}
        int n = image.size();
        int m = image[0].size();
        stack<pair<int,int>> s;
        s.push({sr,sc});
        while(!s.empty())
        {
            pair<int,int> p = s.top();
            s.pop();
            int x = p.first, y = p.second;
            image[x][y] = color;
            if (x+1<n && image[x+1][y] == ele) s.push({x+1,y});
            if (x-1>=0 && image[x-1][y] == ele) s.push({x-1,y});
            if (y+1<m && image[x][y+1] == ele) s.push({x,y+1});
            if (y-1>=0 && image[x][y-1] == ele) s.push({x,y-1});
        }
        return image;
    }
};