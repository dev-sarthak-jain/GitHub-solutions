class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if (s[i] == goal[0])
            {
                int j = i+1, k = 1;
                j = j%n;
                while(j!=i)
                {
                    if (s[j] != goal[k]){break;}
                    j++;k++;
                    j = j%n;k=k%n;
                }
                if (i==j){return true;}
            }
        }
        return false;
    }
};