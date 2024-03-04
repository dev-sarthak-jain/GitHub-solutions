class Solution {
public:
    int recur(vector<int>& nums, int target, int left, int right)
    {
        cout << left << " " << right << endl;
        if (left==right)
        {
            if (nums[left] >= target){return left;}
            else{return left+1;}
        }
        int mid = left + (right-left)/2;
        if (nums[mid] == target){return mid;}
        else if (nums[mid] > target){return recur(nums,target,left,mid);}
        else {return recur(nums,target,mid+1,right);}
    }

    int searchInsert(vector<int>& nums, int target) {
        return recur(nums,target,0,nums.size()-1);
    }
};