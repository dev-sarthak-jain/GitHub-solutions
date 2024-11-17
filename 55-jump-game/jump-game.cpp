class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        if (maxIndex>=n-1){return true;}
        for(int i=0;i<n && i<=maxIndex;i++)
        {
            maxIndex = max(maxIndex,i+nums[i]);
            if (maxIndex>=n-1){return true;}
        }
        return false;
    }
};