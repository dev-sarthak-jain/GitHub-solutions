class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(nums[0] == 0){return 0;}
        short int n = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == 0){return 0;}
            if (nums[i]<0){n*=-1;}
        }
        return (n>0)?1:-1;
    }
};