class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);  // Convert string to lowercase

        while (i < j) {
            if (!iswalnum(s[i])) {
                i++;
            } else if (!iswalnum(s[j])) {
                j--;
            } else {
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
        }

        return true;
    }
};
