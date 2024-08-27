class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alpha(26,0);
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            alpha[word[i]-'a']++;
        }
        sort(alpha.begin(),alpha.end(),greater<int>());
        int ans = 0;
        int res = 1;
        int i=0;
        while(i<26 && alpha[i]!=0)
        {
            for (int j=0;i<26 && j<8;j++)
            {
                ans += res*alpha[i];
                i++;
            }
            res++;
        }
        return ans;

    }
};