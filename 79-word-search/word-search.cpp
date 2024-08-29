class Solution {
public:
    // Function to check if a position is within the board's bounds
    bool valid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    // Recursive function to perform depth-first search
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& check, const string& word, int x, int y, int c, int n, int m) {
        // Check if the current index matches the length of the word
        if (c == word.length()) return true;
        
        // Check bounds and whether the cell has been visited
        if (!valid(x, y, n, m) || check[x][y] || board[x][y] != word[c]) return false;

        // Mark the cell as visited
        check[x][y] = true;

        // Explore all four directions
        bool found = dfs(board, check, word, x + 1, y, c + 1, n, m) ||
                     dfs(board, check, word, x - 1, y, c + 1, n, m) ||
                     dfs(board, check, word, x, y + 1, c + 1, n, m) ||
                     dfs(board, check, word, x, y - 1, c + 1, n, m);

        // Unmark the cell to allow other paths to use it
        check[x][y] = false;

        return found;
    }

    // Main function to start the search
    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Start the DFS if the first character matches
                if (board[i][j] == word[0] && dfs(board, check, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};
