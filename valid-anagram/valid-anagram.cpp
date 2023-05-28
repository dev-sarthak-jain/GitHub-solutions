class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){return 0;}
        int arr[26];
        for(int i=0;i<26;i++)
        {
            arr[i] = 0;
        }
        for(int i=0;i<s.size();i++)
        {
            arr[s[i] - 97]++;
            arr[t[i] - 97]--;
        }
        for(int i=0;i<26;i++)
        {
            if (arr[i] != 0){return 0;}
        }
        return 1;
    }
};