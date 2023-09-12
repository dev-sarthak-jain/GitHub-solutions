class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> map;
        int m = 0;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
            m = (map[s[i]]>m)?map[s[i]]:m;
        }
        vector<int> vec(m+1,0);
        for(auto x:map)
        {
            vec[x.second]++;
        }
        int ans= 0;
        for(int i=m;i>0;i--)
        {
            if (vec[i]>1)
            {
                ans += vec[i]-1;
                vec[i-1] += vec[i] - 1;
            }
        }
        return ans;

    }
};