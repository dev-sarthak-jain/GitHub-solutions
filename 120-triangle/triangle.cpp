class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> vecA(n, 0);
        vector<int> vecB(n, 0);
        
        vector<int>* vecC = &vecA;
        vector<int>* vecD = &vecB;

        for (int i = 0; i < n; i++) {
            (*vecC)[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                (*vecD)[j] = triangle[i][j] + min((*vecC)[j], (*vecC)[j + 1]);
            }
            swap(vecC, vecD);
        }

        return (*vecC)[0];
    }
};
