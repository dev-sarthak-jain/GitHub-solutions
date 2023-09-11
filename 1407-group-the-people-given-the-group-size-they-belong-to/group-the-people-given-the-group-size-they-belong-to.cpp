class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>> answer;
        unordered_map<int,vector<int>> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]].push_back(i);
            if (map[nums[i]].size() == nums[i])
            {
                answer.push_back(map[nums[i]]);
                map[nums[i]] = {};
            }
        }
        return answer;
    }
};