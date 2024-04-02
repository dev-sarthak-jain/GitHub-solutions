class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map(128,-1);
        vector<bool> set (128,0);
        int n = s.length();
        for(int i=0; i<n ;i++)
        {
            if (map[s[i]] == -1)
            {
                if (set[t[i]] == 1){return 0;}
                map[s[i]] = t[i];
                set[t[i]] = 1;
            }
            else
            {
                if (map[s[i]]!=t[i])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};