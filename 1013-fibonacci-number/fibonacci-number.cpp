class Solution {
public:
    int fib(int n) {
        if (n==0){return 0;}
        vector<vector<int>> ans = {{1,1},{1,0}};
        ans = matExpo(ans,n-1);
        return ans[0][0];
    }

    vector<vector<int>> matExpo(vector<vector<int>>& m,int n)
    {
        vector<vector<int>> ans = {{1,0},{0,1}};
        while(n>0)
        {
            if (n&1)
            {
                ans = multiply(ans,m);
            }
            m = multiply(m,m);
            n = n >> 1;
        }
        return ans;
    }

    vector<vector<int>> multiply(vector<vector<int>>& a,vector<vector<int>>& b)
    {
        vector<vector<int>> prod(2,vector<int>(2));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    prod[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return prod;
    }
};