class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> vec(n,0);
        vector<vector<int>> graph = vector<vector<int>>(n);
        for(int i=0;i<pre.size();i++)
        {
            graph[pre[i][0]].push_back(pre[i][1]);
            vec[pre[i][1]]++;
        }
        int total = n;
        while(total)
        {
            int i=0;
            for(;i<n;i++)
            {
                if (vec[i] == 0){vec[i]--;total--;break;}
            }
            if (i==n){return false;}
            for(int j=0;j<graph[i].size();j++)
            {
                vec[graph[i][j]]--;
            }
        }
        return true;;

    }
};