class Solution {
public:
    int myAtoi(string s) {
        int c = 1,i=0;
        long int x = 0;
        while (i < s.length() && s[i] == ' ')
        {
            i++;
        }
        if (i == s.length()){return 0;}
        if (s[i] == '-') {c = -1;i++;}
        else if (s[i] == '+') {i++;}
        while(i<s.length() && s[i]>='0' && s[i]<='9')
        {
            x*=10;
            x+= s[i] - '0';
            if(x>INT_MAX){
                return c==-1?INT_MIN:INT_MAX;
            }
            i++;
        }
        return x*c;
    }
};