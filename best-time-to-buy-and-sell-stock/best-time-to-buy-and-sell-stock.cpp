class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int n = prices.size();
        int s=prices[0],e=0;
        for(int i=1;i<n;i++)
        {
            if (prices[i]<s){s = prices[i];}
            else{m = max(prices[i]-s,m);}
        }
        return m;
    }
};