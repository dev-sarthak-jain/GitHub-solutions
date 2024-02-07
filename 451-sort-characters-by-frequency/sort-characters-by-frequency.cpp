class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> m;
        for(int i=0;i<26; i++) {
            m.push_back({char(i+97),0});
        }
        for(int i=0;i<26; i++) {
            m.push_back({char(i+65),0});
        }
        for(int i=0;i<=9;i++)
        {
            m.push_back({char(i+48),0});
        }
        int n = s.length();
        for (int i=0; i<n; i++) {
            if (s[i]>91){m[s[i]-97].second+=1;}
            else if(s[i]>64) {m[s[i]-39].second+=1;}
            else {m[s[i]+4].second+=1;}
        }
        
        sort(m.begin(), m.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        string ans = "";
        for(int i=0;i<62 && m[i].second!=0;i++) {
            for(int j = 0; j<m[i].second; j++) {
                ans += m[i].first;
            }
        }
        return ans;
    }
};
