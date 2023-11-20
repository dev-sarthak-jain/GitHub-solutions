class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        bool isZero = true;
        bool isZero2 = true;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]!=0)temp *= nums[i];
            else if (isZero) isZero = false;
            else isZero2 = false;
        }
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)nums[i] = (temp * isZero2);
            else nums[i] = (temp/(nums[i]) * isZero);
        }
        return nums;
    }
};