class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<n+1;i++)
        {
            int temp = i;
            int num = 0;
            while(temp)
            {
                num += temp&1;
                temp = temp >> 1;
            }
            ans.push_back(num);
        }
        return ans;
    }
};