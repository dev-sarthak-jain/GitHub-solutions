class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,0);
        vector<vector<int>> graph (n);
        for(int i=0;i<pre.size();i++)
        {
            vis[pre[i][0]]++;
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if (!vis[i]){s.push(i);}
        }
        vector<int> ans;
        while(!s.empty())
        {
            cout << s.size() << " ";
            int x = s.top();
            s.pop();
            ans.push_back(x);
            for(int i=0;i<graph[x].size();i++)
            {
                if (!--vis[graph[x][i]]){s.push(graph[x][i]);}
            }
        }
        if (ans.size()!=n){return {};}
        else{return ans;}
    }
};