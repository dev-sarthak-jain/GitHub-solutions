class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> a(n,0);
        vector<int> b(n,0);
        for(int i=0;i<trust.size();i++)
        {
            a[trust[i][0]-1] = 1;
            b[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++)
        {
            if (!a[i] && b[i] == n-1)
            {
                return i+1;
            }
        }
        return -1;
    }
};