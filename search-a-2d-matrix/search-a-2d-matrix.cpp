class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++)
        {
            if(nums[i][0]<=target && nums[i][m-1]>=target)
            {
                int s = 0,e=m-1,mid;
                while(s<=e)
                {
                    mid = (s+e)/2;
                    if (nums[i][mid] == target){return 1;}
                    else if(nums[i][mid] > target){e = mid-1;}
                    else{s = mid+1;}
                }
                return 0;
            }
        }
        return 0;
    }
};