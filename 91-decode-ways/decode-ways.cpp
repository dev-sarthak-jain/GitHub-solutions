class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n==0 || s[0] == '0'){return 0;}
        int a =1, b= 1;
        for(int i=1;i<n;i++)
        {
            int temp = 0;
            if (s[i] != '0')
            {
                temp+=b;
            }
            int twodigit = stoi(s.substr(i-1,2));
            if (twodigit>=10 && twodigit<=26)
            {
                temp+=a;
            }
            a = b;
            b = temp;
            //cout << a << " " << b << endl;
        }
        return b;
    }
};