class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int s = 0;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if (nums[i] == 0)
            {
                if (count == s - count){ans+=2;}
                if (abs(count + count - s)==1){ans+=1;}
            }
            count += nums[i];
        }
        return ans;
    }
};