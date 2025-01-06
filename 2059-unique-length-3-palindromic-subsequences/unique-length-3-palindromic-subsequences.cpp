class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.length();
        vector<vector<bool>> vec(26,vector<bool>(26,0));
        vector<int> rec(26,-1);
        vector<int> temp (26,0);
        for(int i=0;i<n;i++)
        {
            if (rec[s[i]-'a'] == -1){rec[s[i]-'a'] = i;}
            else
            {
                if (temp[s[i]-'a']==0)
                {
                    temp[s[i] - 'a'] = 1;
                }
                else if (temp[s[i] - 'a']==1)
                {
                    ans++;
                    temp[s[i] - 'a'] = 2;
                }
                int x = rec[s[i]-'a'];
                rec[s[i]-'a'] = i;
                int k = x+1;
                while(k<i)
                {
                    if (!vec[s[i]-'a'][s[k]-'a'])
                    {
                        vec[s[i]-'a'][s[k]-'a'] = 1;
                        ans++;
                    }
                    k++;
                }
            }
        }
        return ans;
    }
};