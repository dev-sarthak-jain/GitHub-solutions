class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int count = 0;
        int last = 0;
        for(int i=0;i<n;i++)
        {
            int num = 0;
            for(int j=0;j<m;j++)
            {
                if (bank[i][j] == '1'){num++;}
            }
            count += (last*num);
            if (num!=0){last = num;}
        }
        return count;
    }
};