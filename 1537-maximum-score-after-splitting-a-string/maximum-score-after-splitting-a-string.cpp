class Solution {
public:
    int maxScore(string s) {
        int countZero = (s[0] == '0');
        int countOne = 0;
        int n = s.length();
        for(int i=1;i<n;i++)
        {
            if (s[i] == '1'){countOne++;}
        }
        int ans = countZero + countOne;
        for(int i=1;i<n-1;i++)
        {
            if (s[i]=='0')
            {
                countZero++;
            }
            else
            {
                countOne--;
            }
            ans = max(ans,countOne+countZero);
        }
        return ans;
    }
};