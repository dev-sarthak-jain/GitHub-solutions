class Solution {
public:
    bool isVovel(string s)
    {
        int n = s.length()-1;
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
        (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u')) return true;

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> vec(n+1,0);
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count += isVovel(words[i]);
            vec[i+1] = count;
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i] = vec[queries[i][1]+1] - vec[queries[i][0]];
        }
        return ans;
    }
};