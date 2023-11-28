#define mod 1000000007

class Solution {
public:
    int numberOfWays(string nums) {
        long long int count = 0,ans = 1,temp=1;
        bool isTrue = 0;
        int i,j=0,n = nums.size();
        while(j<n)
        {
            if (nums[j] == 'S'){isTrue = 1;count++;}
            j++;
            if (count == 2)
            {
                count = 0;
                while(j<n && nums[j]!='S')
                {
                    j++;temp++;
                }
                if (j==n){return ans;}
                ans = (temp*ans)%mod;
                temp = 1;
            }
        }
        if (!isTrue){return 0;}
        if (count!=0){return 0;}
        else{
            return ans;
        }
    }
};