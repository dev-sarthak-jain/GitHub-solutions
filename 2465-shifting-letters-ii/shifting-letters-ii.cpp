class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> vec (n+1,0);
        for(int i=0;i<shifts.size();i++)
        {
            if (shifts[i][2]==1)
            {
                vec[shifts[i][0]] += 1;
                vec[shifts[i][1]+1] -= 1; 
            }
            else
            {
                vec[shifts[i][0]] -= 1;
                vec[shifts[i][1]+1] += 1; 
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=vec[i];
            sum = (sum % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + sum) % 26;
        }
        return s;
    }
};