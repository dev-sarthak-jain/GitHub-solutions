class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int m = nums[0].length();
        int maxi = pow(2,m) - 1;
        vector<bool> arr (maxi,0);
        for (const string& s : nums) {
            int val = 0;
            for (int i = 0; i < m; ++i) {
                val = (val << 1) + (s[i] - '0');
            }
            arr[val] = 1;
        }
        for(int i=0;i<maxi+1;i++)
        {
            if (arr[i] == 0)
            {
            
                string s = std::bitset< 22 >( i ).to_string();
                s = s.substr(22-m);
                return s;
            }
        }
        return "";
    }
};