class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long int> temp(n);
        temp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            temp[i] = temp[i-1] + nums[i];
        }
        cout << endl;
        for(int i=n-1;i>=2;i--)
        {
            if (nums[i]<temp[i-1])
            {
                return temp[i];
            }
        }
        return -1;
    }
};