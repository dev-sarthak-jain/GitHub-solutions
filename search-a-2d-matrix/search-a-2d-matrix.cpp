class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int p=0,q=n-1,i;
        while(p<=q)
        {
            i = (p+q)/2;
            if (nums[i][0]>target){q = i-1;}
            else if (nums[i][m-1]<target){p = i + 1;}
            else{
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