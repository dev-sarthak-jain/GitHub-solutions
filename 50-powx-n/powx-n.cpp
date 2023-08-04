class Solution {
public:
    double myPow(double x, int n) {
        if (n<0)
        {
            x = 1/x;
            n = abs(n);
        }
        double s = 1;
        while(n>0)
        {
            if (n&1)
            {
                s*=x;
            }
            n >>= 1;
            x = x*x;
        }
        return s;

    }
};