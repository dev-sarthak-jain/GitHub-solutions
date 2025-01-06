class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = costs.size();
        vector<int> vec(n+1,INT_MAX);
        vec[0] = 0;
        int temp,cost;
        for(int i=1;i<n+1;i++)
        {
            vec[i] = min(vec[i],vec[i-1]+costs[0]);
            temp = days[i-1] + 7;
            cost = vec[i-1] + costs[1];
            int k = i;
            while(k<n+1 && days[k-1]<temp)
            {
                vec[k] = min(vec[k],cost);
                k++;
            }
            for(int i=1;i<n+1;i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
            temp = days[i-1] + 30;
            cost = vec[i-1] + costs[2];
            k = i;
            while(k<n+1 && days[k-1]<temp)
            {
                vec[k] = min(vec[k],cost);
                k++;
            }
            for(int i=1;i<n+1;i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
        }
        return vec[n];
    }
};