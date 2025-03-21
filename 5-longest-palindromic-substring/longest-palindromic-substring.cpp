class Solution {
public:
    string longestPalindrome(string s) {
        int length = 0;
        string res = "";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && s[l] == s[r])
            {
                if (r-l+1>length)
                {
                    length = r-l+1;
                    res = s.substr(l,(r-l)+1);
                }
                l--;
                r++;
            }
            l = i;r=i+1;
            while(l>=0 && r<n && s[l] == s[r])
            {
                if (r-l+1>length)
                {
                    length = r-l+1;
                    res = s.substr(l,(r-l)+1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};