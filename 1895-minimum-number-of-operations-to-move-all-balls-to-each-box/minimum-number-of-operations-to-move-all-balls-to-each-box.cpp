class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int> ans(n, 0);

        // Prefix sum: Operations to bring '1's from the left
        int count = 0, operations = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = operations;
            if (s[i] == '1') count++;
            operations += count;
        }

        // Suffix sum: Operations to bring '1's from the right
        count = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += operations;
            if (s[i] == '1') count++;
            operations += count;
        }

        return ans;
    }
};
