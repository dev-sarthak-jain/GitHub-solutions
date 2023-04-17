class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int m = 0;
        int n = candies.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++)
        {
            m = (candies[m]>candies[i])?m:i;
        }
        for(int i=0;i<n;i++)
        {
            if (candies[i]+extra >= candies[m]){ans[i] = 1;}
            else{ans[i] = 0;}
        }
        return ans;
    }
};