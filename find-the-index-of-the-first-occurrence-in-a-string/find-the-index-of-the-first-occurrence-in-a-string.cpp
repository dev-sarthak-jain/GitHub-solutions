class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i=0;
        while(i<n)
        {
            if (haystack[i] == needle[0])
            {
                int t = -1;
                int j = 1;
                while(j<m && j+i<n && haystack[j+i] == needle[j])
                {
                    if (t==-1 && haystack[i+j] == needle[0])
                    {
                        t = i+j;
                    }
                    j++;
                }
                if (j==m){return i;}
                else if (t!=-1){i = t-1;}
                else
                {
                    i = i+j-1;
                }
            }
            i++;
        }
        return -1;
    }
};