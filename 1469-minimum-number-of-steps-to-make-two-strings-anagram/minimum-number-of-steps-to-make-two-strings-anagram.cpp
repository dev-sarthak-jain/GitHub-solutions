class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int sum = 0;
        for (int count : freq) {
            if (count > 0) {
                sum += count;
            }
        }

        return sum;
    }
};
