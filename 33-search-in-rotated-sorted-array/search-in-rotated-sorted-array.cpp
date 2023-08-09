class Solution {
public:
    int search(vector<int>& nums, int target) {
        int x = 0, y = nums.size()-1;
        while(x<=y)
        {
            int mid = x + (y-x)/2;
            if (target == nums[mid]){return mid;}
            else if (nums[mid]>=nums[x])
            {
                if (nums[mid]<target){x = mid+1;}
                else
                {
                    if (target<nums[x]){x = mid+1;}
                    else{y = mid-1;}
                }
            }
            else
            {
                if (nums[mid]>target){y = mid-1;}
                else
                {
                    if (target<=nums[y]){x = mid+1;}
                    else{y = mid-1;}
                }
            }
        }
        return -1;
    }
};