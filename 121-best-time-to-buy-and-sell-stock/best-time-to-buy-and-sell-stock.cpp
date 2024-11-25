class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_dif = 0;
        
        int n = prices.size();
        int maxi = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if (prices[i]>maxi)
            {
                maxi=prices[i];
            }
            else
            {
                max_dif = max(max_dif,maxi - prices[i]);
            }
        }
        return max_dif;
    }
};