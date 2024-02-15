class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        int x,y;
        for(int i=0;i<n;i++)
        {
            x = 0;y = words[i].size()-1;
            while(x<y)
            {
                if (words[i][x]!=words[i][y])
                {
                    break;
                }
                x++;y--;
            }
            if (x>=y)
            {
                return words[i];
            }
        }
        return "";
    }
};