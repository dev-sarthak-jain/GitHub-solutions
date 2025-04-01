class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int i=0,j,k=n-1;
        while(i<n && s[i] == '0'){i++;}
        j = i;
        long long int score = 0;
        while(j<n && s[j] == '1'){j++;}
        while(j<n)
        {
            score += j-i;
            i++;
            j++;
            while(j<n && s[j] == '1'){j++;}
        }
        return score;
    }
};