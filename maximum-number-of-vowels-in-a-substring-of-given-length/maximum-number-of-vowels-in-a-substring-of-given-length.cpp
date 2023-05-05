class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> check({'a','e','i','o','u'});
        int i=0,j=0;
        int m = 0;
        while(j<k)
        {
            if (check.find(s[j]) != check.end()){m++;}
            j++;
        }
        int count = m;
        while(j<s.length())
        {
            if (check.find(s[i]) != check.end()){count--;}
            if (check.find(s[j]) != check.end()){count++;}
            m = max(count,m);
            //if (m==k){return m;}
            i++;j++;
        }
        return m;
    }
};