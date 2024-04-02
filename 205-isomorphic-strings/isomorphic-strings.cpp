class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_set<char> set;
        int n = s.length();
        for(int i=0; i<n ;i++)
        {
            if (map.count(s[i]) == 0)
            {
                if (set.find(t[i]) != set.end()){return 0;}
                map[s[i]] = t[i];
                set.insert(t[i]);
            }
            else
            {
                if (map[s[i]]!=t[i])
                {
                    return 0;
                }
            }
            cout << s[i] << " " << t[i] << map[s[i]] << endl;
        }
        return 1;
    }
};