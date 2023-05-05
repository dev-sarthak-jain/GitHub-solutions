class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<bool> temp(10,0);
        vector<vector<bool>> row(9,temp);
        vector<vector<bool>> col(9,temp);
        vector<vector<bool>> sect(9,temp);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if (b[i][j] == '.') { continue;}
                int x = b[i][j] - 48;
                if (row[i][x] == 1){return 0;}
                else {row[i][x] = 1;}
                if (col[j][x] == 1){return 0;}
                else {col[j][x] = 1;}
                if (sect[((i/3)*3 + j/3)][x] == 1){return 0;}
                else {sect[((i/3)*3 + j/3)][x] = 1;}
            }
        }
        return 1;
    }
};