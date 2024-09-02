class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        int n = chalk.size();
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
        }
        sum = k%sum;
        cout << sum << endl;
        int i=0;
        while(sum>=0 && i<n)
        {
            sum-=chalk[i];
            i++;
        }
        return --i;
    }
};