class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<bool> temp(10, false);
        vector<vector<bool>> row(9, temp);
        vector<vector<bool>> col(9, temp);
        vector<vector<bool>> sect(9, temp);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') continue;
                int x = b[i][j] - '0';
                if (row[i][x] || col[j][x] || sect[(i / 3) * 3 + j / 3][x]) return false;
                row[i][x] ? false : row[i][x] = true;
                col[j][x] ? false : col[j][x] = true;
                sect[(i / 3) * 3 + j / 3][x] ? false : sect[(i / 3) * 3 + j / 3][x] = true;
            }
        }
        return true;
    }
};