class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary[0],m = salary[0];
        double avg = salary[0];
        for(int i = 1;i<salary.size();i++)
        {
            avg += salary[i];
            n = max(n,salary[i]);
            m = min(m,salary[i]);
        }
        if(n==m){avg -= n;return avg/(salary.size()-1);}
        else{
            avg-=n;avg-=m;
            return avg/(salary.size()-2);
        }
    }
};