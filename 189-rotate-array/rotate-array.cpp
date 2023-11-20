class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(),j,z;
        k = k%n;
        vector<bool> check(n,0);
        for(int i=0; i<k; i++)
        {
            j = i;
            int temp1 = nums[j];
            int temp2;
            while(check[j]==0)
            {
                check[j] = 1;
                z = (j+k)%n;
                temp2 = nums[z];
                nums[z] = temp1;
                temp1 = temp2;
                j = z;
            }
        }
    }
};