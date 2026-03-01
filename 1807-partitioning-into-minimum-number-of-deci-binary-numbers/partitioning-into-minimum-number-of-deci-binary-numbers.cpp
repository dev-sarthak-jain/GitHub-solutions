class Solution {
public:
    int minPartitions(string s) {
        int m = 0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            m = max(m,s[i]-'0');
        }
        return m;
    }
};