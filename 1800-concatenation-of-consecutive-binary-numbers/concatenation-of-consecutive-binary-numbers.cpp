#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans = 1;
        long long int res = 2;
        for(int i=2;i<n+1;i++)
        {
            ans = ans << res;
            if (i == pow(2,res)-1){res=res+1;}
            ans = ans | i;
            ans = ans%MOD;
            
        }
        return ans;
    }
};