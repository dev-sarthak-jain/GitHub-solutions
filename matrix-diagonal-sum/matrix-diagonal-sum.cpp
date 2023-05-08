class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int s = (n&1)?-mat[n/2][n/2]:0;
        for(int i=0;i<n;i++)
        {
            s += mat[i][i];
        }
        for(int i=0;i<n;i++)
        {
            s += mat[i][n-i-1];
        }
        return s;
    }
};