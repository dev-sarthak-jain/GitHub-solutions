#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        long int ans = 0;
        long int res = 0;
        for(int i=1;i<n+1;i++)
        {
            if ((i&(i-1)) == 0){res++;}
            ans = ((ans << res)|i)%MOD;
        }
        return ans;
    }
};