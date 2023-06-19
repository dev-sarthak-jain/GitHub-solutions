class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m = 0,curr = 0;
        for(int i = 0;i<gain.size();i++)
        {
            curr+=gain[i];
            m = max(curr,m);
        }
        return m;
    }
};