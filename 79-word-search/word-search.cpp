class Solution {
public:
    int n,m,wsize;
    string words;
    bool valid(int x,int y, int n, int m)
    {
        if (x>=0 && x<n && y>=0 && y<m){return true;}
        else{return false;}
    }

    bool func(vector<vector<char>>& board,vector<vector<bool>>& check, int x, int y, int c)
    {
        if (c==wsize){return true;}
        if (valid(x,y,n,m) && !check[x][y] && words[c] == board[x][y])
        {
            check[x][y] = 1;
            if (
            func(board,check,x+1,y,c+1) ||
            func(board,check,x-1,y,c+1) ||
            func(board,check,x,y+1,c+1) ||
            func(board,check,x,y-1,c+1))
            {return 1;}
            check[x][y] = 0;
        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        wsize = word.length();
        words = word;
        vector<vector<bool>> check(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j] == word[0])
                {
                    check[i][j] = 1;
                    if (
                    func(board,check,i+1,j,1) ||
                    func(board,check,i-1,j,1) ||
                    func(board,check,i,j+1,1) ||
                    func(board,check,i,j-1,1))
                    {return 1;}
                    check[i][j] = 0;
                }
            }
        }
        return 0;
    }
};