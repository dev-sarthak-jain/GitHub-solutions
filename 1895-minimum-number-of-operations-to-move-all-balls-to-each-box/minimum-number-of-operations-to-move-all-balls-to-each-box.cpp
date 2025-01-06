class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int> vec;
        vector<int> ans (n,0);
        for(int i=0;i<n;i++)
        {
            if (s[i]=='1'){
                for(int j=0;j<n;j++)
                {
                    ans[j] += abs(i-j);
                }
            }
        }
        return ans;
    }
};