class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int,int>> vec(26,{-1,-1});
        for(int i=0;i<n;i++)
        {
            if (vec[s[i] - 'a'].first==-1){vec[s[i] - 'a'].first = i;}
        }
        for(int i=n-1;i>=0;i--)
        {
            if (vec[s[i] - 'a'].second==-1){vec[s[i] - 'a'].second = i;}
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            vector<bool> rec(26,0);
            int x = vec[i].first, y = vec[i].second;
            for(int j=x+1;j<y;j++)
            {
                if (!rec[s[j]-'a'])
                {
                    rec[s[j]-'a'] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};