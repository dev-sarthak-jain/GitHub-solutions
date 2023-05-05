class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int m = 0;
        while(j<k)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                m++;
            }
            j++;
        }
        int count = m;
        while(j<s.length())
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count--;
            }
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                count++;
            }
            m = max(count,m);
            if (m==k){return m;}
            i++;j++;
        }
        return m;
    }
};