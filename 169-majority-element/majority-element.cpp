class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, freq = 0;
        int n = nums.size();
        for(int i=0;i<n;)
        {

            int cur_freq = 0;
            int j = i;
            for(;j<n && nums[j] == nums[i];j++)
            {
                cur_freq++;
            }
            if (nums[i] == ele)
            {
                freq += cur_freq;
            }
            else if (freq<cur_freq)
            {
                freq = cur_freq-freq;
                ele = nums[i];
            }
            else
            {
                freq-=cur_freq;
            }
            i = j;
        }
        return ele;
    }
};