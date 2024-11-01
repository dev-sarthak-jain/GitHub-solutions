class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){return nums[0];}
        if (n==2){return max(nums[0],nums[1]);}
        if (n==3){return max(nums[0],max(nums[1],nums[2]));}
        int ans1,ans2;
        int a = nums[0], b = max(nums[0],nums[1]);
        int temp;
        for(int i=2;i<n-1;i++)
        {
            temp = max(b,a+nums[i]);
            a = b;
            b = temp;
        }
        ans1 = b;
        a = nums[1], b = max(nums[1],nums[2]);
        for(int i=3;i<n;i++)
        {
            temp = max(b,a+nums[i]);
            a = b;
            b = temp;
        }
        return max(ans1,b);

    }
};