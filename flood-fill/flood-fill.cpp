class Solution {
public:
    int n,m,old,color;
    void recur(vector<vector<int>>& image, int sr, int sc)
    {
        if (sr>=0 && sr<n && sc >=0 && sc < m && image[sr][sc] == old)
        {
            image[sr][sc] = color;
            recur(image,sr+1,sc);
            recur(image,sr,sc+1);
            recur(image,sr-1,sc);
            recur(image,sr,sc-1);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int next) {
        old = image[sr][sc];
        if (old == next){return image;}
        color = next;
        n = image.size();
        m = image[0].size();
        recur(image,sr,sc);
        return image;
    }
};