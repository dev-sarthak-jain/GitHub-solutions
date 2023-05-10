class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n);
        vector<vector<int>> ans(n,temp);
        int x=0;
        int a = 1;
        while(x != n)
        {
            for(int i=x;i < n-x ;i++)
            {
                ans[x][i] = a;
                a++;
            }
            for(int i=x+1;i<n-x;i++)
            {
                ans[i][n-x-1] = a;
                a++;
            }
            for(int i=n-x-2;i>=x;i--)
            {
                ans[n-x-1][i] = a;
                a++;
            }
            for(int i=n-x-2;i>=x+1;i--)
            {
                ans[i][x] = a;
                a++;
            }
            x++;
        }
        return ans;
    }
};