class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.length();
        int i = 0, x=0;
        for(;i<n;i++)
        {
          if (nums[i] % 2 != 0)
          {
              x = i+1;
          }
        }
        return nums.substr(0,x);
    }
};