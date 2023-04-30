class Solution {
public:
    int countPrimes(int n) {
        int* a = new int[n];
        int ans = 0;
        if(n>2){ans = 1;}
        for(int i=3;i<n;i+=2)
        {
            a[i] = 1;
        }
        for(long int i=3;i<n;i+=2)
        {
            if (a[i] == 1)
            {
                ans++;
                //if(i >=pow(n,.5)){continue;}
                for(long int j=i*i;j<n;j+=i)
                {
                    a[j] = 0;
                }
            }
        }
        return ans;
    }
};