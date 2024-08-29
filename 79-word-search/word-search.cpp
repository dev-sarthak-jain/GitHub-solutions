class Solution {
public:
    bool valid(int x,int y, int n, int m)
    {
        if (x>=0 && x<n && y>=0 && y<m){return true;}
        else{return false;}
    }

    bool func(vector<vector<char>>& board,vector<vector<bool>>& check, string word, int x, int y, int c, int n, int m)
    {
        if (c==word.length()){return true;}
        if (valid(x,y,n,m) && !check[x][y])
        {
            if (word[c] == board[x][y])
            {
                check[x][y] = 1;
                if (
                func(board,check,word,x+1,y,c+1,n,m) ||
                func(board,check,word,x-1,y,c+1,n,m) ||
                func(board,check,word,x,y+1,c+1,n,m) ||
                func(board,check,word,x,y-1,c+1,n,m))
                {return 1;}
                check[x][y] = 0;
            }
        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int c = word.size();
        vector<vector<bool>> check(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j] == word[0])
                {
                    check[i][j] = 1;
                    if (
                    func(board,check,word,i+1,j,1,n,m) ||
                    func(board,check,word,i-1,j,1,n,m) ||
                    func(board,check,word,i,j+1,1,n,m) ||
                    func(board,check,word,i,j-1,1,n,m))
                    {return 1;}
                    check[i][j] = 0;
                }
            }
        }
        return 0;
    }
};