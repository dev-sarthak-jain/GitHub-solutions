class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if (n<3){return s;}
        string ans = "";
        ans = ans + s[0] + s[1];
        for(int i=2;i<s.length();i++)
        {
            if (s[i] == s[i-1] && s[i]==s[i-2])
            {
                continue;
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};