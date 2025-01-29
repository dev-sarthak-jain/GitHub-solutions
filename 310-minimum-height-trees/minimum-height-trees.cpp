class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& pre) {
        if (n==1){return {0};}
        else if (n==2){return {0,1};}
        vector<vector<int>> graph(n);
        vector<int> vis(n,0);
        for(int i=0;i<pre.size();i++)
        {
            vis[pre[i][0]]++;
            vis[pre[i][1]]++;
            graph[pre[i][0]].push_back(pre[i][1]);
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> s;
        for(int i=0;i<n;i++)
        {
            if (vis[i]==1){s.push(i);}
        }
        int total = n;
        while(total > 2 )
        {
            int m = s.size();
            total = total-s.size();
            while(m)
            {
                int x = s.front();
                s.pop();
                for(int j=0;j<graph[x].size();j++)
                {
                    if (--vis[graph[x][j]] == 1)
                    {
                        s.push(graph[x][j]);
                    }
                }
                m--;
            }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.front());
            s.pop();
        }
        return ans;
    }
};