class Solution {
public:
    int n;
    double m;
    int x,y;
    bool recur(vector<vector<int>>& nums,int a)
    {
        if (a == n){return 1;}
        int denom = x-nums[a][0];
        if (denom == 0){return 0;}
        if (m == (double(y-nums[a][1]))/denom){return recur(nums,a+1);}
        else{return 0;}

    }
    bool denominator(vector<vector<int>>& nums,int a)
    {
        if (a == n){return 1;}
        int denom = x-nums[a][0];
        if (denom == 0){return denominator(nums,a+1);}
        else{return 0;}
    }

    bool checkStraightLine(vector<vector<int>>& nums) {
        n = nums.size();
        x = nums[0][0];
        y = nums[0][1];
        int denom = nums[1][0]-x;
        if (denom == 0){return denominator(nums,2);}
        m = (double(nums[1][1]-y))/(nums[1][0]-x);
        return recur(nums,2);
    }
};