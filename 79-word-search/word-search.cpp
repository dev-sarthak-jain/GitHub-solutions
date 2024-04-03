class Solution {
public:
    int m,n;
    bool bound(int i, int j)
    {
        if (i<0 || i>=n || j<0 || j>=m){return 0;}
        else {return 1;}
    }

    bool func(vector<vector<char>>& board, string& word,vector<vector<bool>>& check, int i,int j, int k)
    {
        if (k == word.length()){return 1;}
        if (bound(i+1,j) && check[i+1][j] == 0 && board[i+1][j] == word[k]){
            check[i+1][j] = 1;
            if (func(board,word,check,i+1,j,k+1)){return 1;}
            check[i+1][j] = 0;
        }
        if (bound(i-1,j) && check[i-1][j] == 0 && board[i-1][j] == word[k]){
            check[i-1][j] = 1;
            if (func(board,word,check,i-1,j,k+1)){return 1;}
            check[i-1][j] = 0;
        }
        if (bound(i,j+1) && check[i][j+1] == 0 && board[i][j+1] == word[k]){
            check[i][j+1] = 1;
            if (func(board,word,check,i,j+1,k+1)){return 1;}
            check[i][j+1] = 0;
        }
        if (bound(i,j-1) && check[i][j-1] == 0 && board[i][j-1] == word[k]){
            check[i][j-1] = 1;
            if (func(board,word,check,i,j-1,k+1)){return 1;}
            check[i][j-1] = 0;
        }
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> check (n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[i][j] == word[0])
                {
                    check[i][j] = 1;
                    if (func(board,word,check,i,j,1) == 1){return 1;}
                    check[i][j] = 0;
                }
            }
        }
        return 0;
    }
};