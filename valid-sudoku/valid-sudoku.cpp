class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> used(10, false);
        vector<int> row(9), col(9), sec(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int secIdx = i/3 * 3 + j/3;
                    if(used[num] || row[i] & (1<<num) || col[j] & (1<<num) || sec[secIdx] & (1<<num)) {
                        return false;
                    }
                    used[num] = true;
                    row[i] |= (1<<num);
                    col[j] |= (1<<num);
                    sec[secIdx] |= (1<<num);
                }
            }
            used.assign(10, false);
        }
        return true;
    }
};