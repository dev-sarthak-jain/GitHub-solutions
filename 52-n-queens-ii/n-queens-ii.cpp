class Solution {
public:

    bool valid(vector<string>&check, int x, int y, int n)
    {
        for (int i=x-1;i>=0;i--)
        {
            if (check[i][y] == 'Q'){return 0;}
        }
        int a = x-1, b= y-1;
        while(a>=0 && b>=0)
        {
            if (check[a][b] == 'Q'){return 0;}
            a--;b--;
        }
        a = x-1;
        b = y+1;
        while (a>=0 && b<n)
        {
            if (check[a][b] == 'Q'){return 0;}
            a--;b++;
        }
        return 1;
    }
    
    void func(vector<vector<string>>& answer, vector<string>& check, int n, int z)
    {
        if (n==z){answer.push_back(check);}


        for (int i=0; i<n;i++)
        {
            if (valid(check,z,i,n))
            {
                check[z][i] = 'Q';
                func(answer,check,n,z+1);
                check[z][i] = '.';
            }
        }
        return;
    }

    int solveNQueens(int n) {
        string s = "";
        for(int i=0;i<n;i++)
        {
            s+= ".";
        }
        vector<string> check(n,s);
        vector<vector<string>> ans;
        func(ans,check,n,0);
        return ans.size();
    }

    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};