#define check1 if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
#define check2 if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')

class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int m = 0;
        while(j<k)
        {
            check1
            {
                m++;
            }
            j++;
        }
        int count = m;
        while(j<s.length())
        {
            check2
            {
                count--;
            }
            check1
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