class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = n + m;
        int quant = (total + 1) / 2;
        int x = 0, y = m;

        while (x <= y) {
            int midS = (x + y) / 2;
            int midL = quant - midS;

            int SLeft = (midS > 0) ? nums2[midS - 1] : INT_MIN;
            int SRight = (midS < m) ? nums2[midS] : INT_MAX;
            int LLeft = (midL > 0) ? nums1[midL - 1] : INT_MIN;
            int LRight = (midL < n) ? nums1[midL] : INT_MAX;

            if (SLeft <= LRight && LLeft <= SRight) {
                if (total % 2 == 1) {
                    return max(SLeft, LLeft);
                } else {
                    return (max(SLeft, LLeft) + min(SRight, LRight)) / 2.0;
                }
            } else if (SLeft > LRight) {
                y = midS - 1;
            } else {
                x = midS + 1;
            }
        }
        return 0.0;
    }
};