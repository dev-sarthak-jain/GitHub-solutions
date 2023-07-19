class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        for (int i=0;i<nums.size();i++)
        {
            cout << nums[i][0] << nums[i][1] << " ";
        }
        cout << endl;
        int c = 0, i=0,j=1;
        while(j<nums.size())
        {
            if (nums[i][1]>nums[j][0]){j++;c++;}
            else{i=j;j++;}
        }
        return c;
    }
};