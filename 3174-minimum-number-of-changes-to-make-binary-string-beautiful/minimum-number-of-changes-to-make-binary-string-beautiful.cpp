class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count = 0;
        for(int i=1;i<n;i++)
        {
            int len = 1;
            while(i<n && s[i]==s[i-1])
            {
                i++;
                len++;
            }
            if (len%2 != 0){count++;i++;}

        }
        return count;
    }
};