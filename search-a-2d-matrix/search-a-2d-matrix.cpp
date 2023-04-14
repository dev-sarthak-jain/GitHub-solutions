class Solution {
public:
    bool binarySearch(vector<int> nums,int target, int s,int e)
    {
        if (s>e){return 0;}
        int m = (s+e)/2;
        if (nums[m] == target){return 1;}
        else
        {
            return (binarySearch(nums,target,s,m-1) || binarySearch(nums,target,m+1,e));
        }
    }

    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++)
        {
            if(nums[i][0]<=target && nums[i][m-1]>=target)
            {
                bool ret = binarySearch(nums[i],target,0,m-1);
                if (ret == 1){return 1;}
            }
        }
        return 0;
    }
};