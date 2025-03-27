class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0];
        int count = 1, total = 0;
        for(int i=1;i<n;i++)
        {
            if (nums[i]!=majority && count == 0){majority = nums[i];count = 1;}
            else if (nums[i] == majority){count++;}
            else{count--;}
        }
        for(int i=0;i<n;i++)
        {
            if (majority==nums[i]){total++;}
        }
        count = 0;
        for(float i=0;i<n-1;i++)
        {
            if (nums[i] == majority){count++;}
            if ((i+1)/2<count && (n-i-1)/2<(total-count)){return i;}
        }
        return -1;
    }
};