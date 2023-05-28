class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0){return 0;}

        unordered_set<char> check;
        check.insert(s[0]);
        int ans = 1;
        int i = 0,j=1;
        while(j<n)
        {
            while(j<n && check.find(s[j])==check.end())
            {
                check.insert(s[j]);
                j++;
            }
            ans = max(ans,j-i);
            if (j!=n)
            {
                while(s[i]!=s[j])
                {
                    check.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};