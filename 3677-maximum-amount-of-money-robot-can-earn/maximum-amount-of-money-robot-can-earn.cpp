class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> memo;

    int func(vector<vector<int>>& coins, int x, int y, int neu) {
        if (x >= n || y >= m) return INT_MIN;

        if (x == n - 1 && y == m - 1) {
            // Handle last cell: consider skipping it if `neu > 0`
            return coins[x][y] < 0 && neu > 0 ? 0 : coins[x][y];
        }

        if (memo[x][y][neu] != INT_MIN) return memo[x][y][neu];

        int maxPath = INT_MIN;

        // Normal moves
        if (x + 1 < n) maxPath = max(maxPath, coins[x][y] + func(coins, x + 1, y, neu));
        if (y + 1 < m) maxPath = max(maxPath, coins[x][y] + func(coins, x, y + 1, neu));

        // Skip negative cell if `neu > 0`
        if (neu > 0 && coins[x][y] < 0) {
            if (x + 1 < n) maxPath = max(maxPath, func(coins, x + 1, y, neu - 1));
            if (y + 1 < m) maxPath = max(maxPath, func(coins, x, y + 1, neu - 1));
        }

        return memo[x][y][neu] = maxPath;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return func(coins, 0, 0, 2);
    }
};
