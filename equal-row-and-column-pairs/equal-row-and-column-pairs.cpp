class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        unordered_map<vector<int>, vector<int>, VectorHash> map;
        for (int i = 0; i < n; i++) {
            map[grid[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                temp[j] = grid[j][i];
            }
            ans += map[temp].size();
        }
        return ans;
    }
};
