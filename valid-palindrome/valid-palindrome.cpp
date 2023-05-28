class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j = s.size()-1;
        while(i<j)
        {
            if (iswalnum(s[i]) == 0){i++;}
            else if(iswalnum(s[j]) == 0){j--;}
            else
            {
                if (tolower(s[i]) != tolower(s[j])){return 0;}
                i++;j--;
            }
        }
        return 1;
    }
};