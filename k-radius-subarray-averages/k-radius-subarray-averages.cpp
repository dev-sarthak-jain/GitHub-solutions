class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k==0){return nums;}
        int n = nums.size(),m=2*k + 1;
        vector<int> ans(n,-1);
        if (n<m){return ans;}
        int i = k;
        long long int sum = 0;
        for(int i=0;i<m;i++)
        {
            sum+=nums[i];
        }
        ans[i] = sum/m;
        sum-=nums[0];
        i++;
        while(i+k<n)
        {
            //cout << sum << endl;
            sum  = sum + nums[i+k];
            ans[i] = sum/m;
            sum -= nums[i-k];
            i++;
        }
        return ans;

    }
};
