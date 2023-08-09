#define rf return recur(nums,mid+1,y)
#define lf return recur(nums,x,mid-1)
class Solution {
public:
    int target;
    int recur(vector<int>& nums, int x, int y)
    {
        if (x>y){return -1;}

        int mid = x + (y-x)/2;
        if (nums[mid] == target){return mid;}
        else if (nums[mid]>=nums[x])
        {
            if (nums[mid]<target){rf;}
            else{
                if (target<nums[x]){rf;}
                else{lf;}
            }
        }
        else
        {
            if (target<nums[mid]){lf;}
            else{
                if (target<=nums[y]){rf;}
                else{lf;}
            }
        }
    }

    int search(vector<int>& nums, int t) {
        target = t;
        return recur(nums,0,nums.size()-1);
    }
};