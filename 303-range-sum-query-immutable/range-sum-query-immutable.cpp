class NumArray {
public:
    vector<int> vec = {0};
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0; i<n; i++)
        {
            s+=nums[i];
            vec.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return vec[right+1] - vec[left];
    }
};