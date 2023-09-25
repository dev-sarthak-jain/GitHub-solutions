class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            m[s[i]]--;
            m[t[i]]++;
        }
        m[t[n]]++;
        for(auto x: m)
        {
            if (x.second == 1){return x.first;}
        }
        return 'a';
    }
};