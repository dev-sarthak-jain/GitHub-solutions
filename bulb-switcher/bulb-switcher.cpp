class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i=1;i*i<n+1;i++)
        {
            ans++;
        }
        return ans;
    }
};