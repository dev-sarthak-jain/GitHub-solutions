class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count_one = 0, n = s.size();
        for(int i=0;i<n;i++)
        {
            if (s[i] == '1'){count_one++;}
        }
        int count_zero = n-count_one;
        string ans = "";
        for(int i=1;i<count_one;i++)
        {
            ans += '1';
        }
        for(int i=0;i<count_zero;i++)
        {
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};