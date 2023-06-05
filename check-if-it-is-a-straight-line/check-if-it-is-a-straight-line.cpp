class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        float m;
        int n,x,y;
        n = nums.size();
        x = nums[0][0];
        y = nums[0][1];
        int denom = nums[1][0]-x;
        if (denom == 0)
        {
            for(int i=2;i<n;i++)
            {
                if (x - nums[i][0] != 0){return 0;}
            }
            return 1;
        }
        else
        {
            m = (float(nums[1][1]-y))/denom;
            for(int i=2;i<n;i++)
            {
                if (m != (double(nums[i][1]-y))/(nums[i][0]-x)){return 0;}
            }
            return 1;
        }
    }
};