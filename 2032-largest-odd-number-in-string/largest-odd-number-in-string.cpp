class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.length();
        int i = 0;
        while(i<n && nums[i] == '0')
        {
          i++;
        }
        int j = i,x = i;
        for(;i<n;i++)
        {
          if (nums[i] % 2 != 0)
          {
              x = i+1;
          }
        }
        cout << j << x << endl;
        return nums.substr(j,x-j);
    }
};