#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> count(n + 1, 0);

        // Count the number of papers with each citation count
        for (int citation : nums) {
            if (citation >= n) {
                count[n]++;
            } else {
                count[citation]++;
            }
        }

        int hIndex = 0;
        for (int i = n; i >= 0; i--) {
            hIndex += count[i];
            if (hIndex >= i) {
                return i;
            }
        }

        return 0;
    }
};
