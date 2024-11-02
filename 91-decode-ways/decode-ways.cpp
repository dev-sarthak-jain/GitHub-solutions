class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int a,b;
        if (n==1){
            if (s[0] == '0'){return 0;}
            return 1;
        }
        if (s[0] == '0'){return 0;}
        else {a=1;}

        if (s[1] == '0' && s[0]>'2'){return 0;}
        else if (s[1] == '0' && s[0]<'3'){b=1;}
        else if (s[0]=='1'){b=2;}
        else if (s[0]=='2' && s[1]<'7'){b=2;}
        else {b=1;}
        cout << a << " " << b << endl;
        int temp;
        for(int i=2;i<n;i++)
        {cout << "i is " << i << endl;
            temp = 0;
            if (s[i] == '0')
            {
                if (s[i-1] == '0' || s[i-1]>'2'){return 0;}
                else {temp += a;}
            }
            else if (s[i-1] == '0')
            {
                temp = b;
            }
            else if (s[i-1]<'3')
            {
                if (s[i-1]=='1')
                {
                    temp = a+b;
                }
                else if (s[i]<'7') 
                {
                    temp = a+b;
                }
                else{temp = b;}
            }
            else
            {
                temp =b;
            }
            a = b;
            b = temp;
            cout << b << endl;
        }
        return b;

    }
};