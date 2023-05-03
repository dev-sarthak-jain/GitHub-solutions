class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){return nums[0];}
        int arr[n+1];
        arr[0] = 0;
        arr[1] = nums[0];
        for(int i=2;i<n+1;i++)
        {
            arr[i] = max(nums[i-1]+arr[i-2],arr[i-1]);
        }
        return arr[n];
    }
};