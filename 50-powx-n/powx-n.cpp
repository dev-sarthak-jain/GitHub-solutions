class Solution {
public:
    double recur(double x, int n)
    {
        if (n==0){return 1;}

        double temp = recur(x,n/2);
        temp = temp*temp;
        if (n%2!=0)
        {
            temp *= x;
        }
        return temp;
    }

    double myPow(double x, int n) {
        double ans = recur(x,n);
        if (n<0)
        {
            return (1/ans);
        }
        else return ans;
    }
};