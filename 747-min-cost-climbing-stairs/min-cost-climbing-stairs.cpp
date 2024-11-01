class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==1){return cost[0];}
        if (n==2){return min(cost[0],cost[1]);}
        int a = cost[0];
        int b = cost[1];
        int temp;
        for(int i=2;i<n;i++)
        {
            temp = min(a,b) + cost[i];
            a = b;
            b = temp;
        }
        return min(a,b);
    }
};