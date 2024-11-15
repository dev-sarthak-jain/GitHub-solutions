class Solution {
public:
    int maxLen = 0;
    int n;
    bool func(string& s, unordered_set<string>& set,vector<bool>& check, int x)
    {
        if (x==n){return true;}
        if (check[x]==0){return check[x];}
        for(int i=x;i<n;i++)
        {
            if (i-x+1>maxLen){check[x]=0;return 0;}
            if (set.find(s.substr(x,i-x+1))!=set.end())
            {
                if (func(s,set,check,i+1) == true){return 1;}
            }
        }
        check[x]=0;
        return 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        n = s.length();
        vector<bool> check(n,1);
        for(int i=0;i<wordDict.size();i++)
        {
            maxLen = max(maxLen, (int)wordDict[i].length());
            set.insert(wordDict[i]);
        }
        return func(s,set,check,0);
    }
};