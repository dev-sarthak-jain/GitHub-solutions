class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,k=0;
        int n = word1.size();
        int m = word2.size();
        string s(n+m,0);
        while(i<n && j<m)
        {
            s[k] = word1[i];
            k++;
            s[k] = word2[j];
            k++;i++;j++;
        }
        while(i<n)
        {
            s[k] = word1[i];
            k++;
            i++;
        }
        while(j<m)
        {
            s[k] = word2[j];
            k++;
            j++;
        }
        return s;
    }
};