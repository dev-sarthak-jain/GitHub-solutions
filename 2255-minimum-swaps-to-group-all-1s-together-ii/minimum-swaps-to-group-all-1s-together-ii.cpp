#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Count the total number of 1's in the array
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                total++;
            }
        }

        if (total < 2) {
            return 0;
        }

        int ans = INT_MAX, count = 0;

        for (int i = 0; i < total; i++) {
            if (nums[i]) {
                count++;
            }
        }

        ans = min(ans, total - count);

        for (int i = 1; i < n; i++) {
            if (nums[i - 1]) {
                count--;
            }
            if (nums[(i + total - 1) % n]) {
                count++;
            }
            ans = min(ans, total - count);
        }

        return ans;
    }
};
