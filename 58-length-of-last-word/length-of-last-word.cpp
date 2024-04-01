class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        while(s[i]==' '){i--;}
        n = i;
        for(;i>=0;i--)
        {
            if (s[i] == ' ')
            {
                return n-i;
            }
        }
        return n-i;
    }
};