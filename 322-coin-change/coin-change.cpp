class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long int> vec(amount+1,-1);
        long int n = coins.size();
        vec[0] = 0;
        sort(coins.begin(),coins.end());
        for(long int i=0;i<=amount;i++)
        {
            if (vec[i] == -1){continue;}
            for(long int j=0;j<n;j++)
            {
                if (i+coins[j]<=amount)
                {
                    if (vec[i+coins[j]] == -1){vec[i+coins[j]] = vec[i]+1;}
                    else {vec[i+coins[j]] = min(vec[i+coins[j]],vec[i]+1);}

                }
                else
                {
                    break;
                }
            }
        }
        return vec[amount];
    }
};