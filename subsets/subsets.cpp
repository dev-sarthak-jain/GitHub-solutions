class Solution {
public:
    vector<vector<int>> answer;
    vector<int> temp;
    int n;
    void recur(vector<int>& nums, int x)
    {
        if (n==0){answer.push_back(temp);return;}

        for(int i=x;i<n;i++)
        {
            temp.push_back(nums[i]);
            answer.push_back(temp);
            recur(nums,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        answer.push_back(temp);
        recur(nums,0);
        return answer;
    }
};