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
        queue<int> que;
        for(int i=0;i<n;i++)
        {
            if (vec[i] == 0){que.push(i);}
        }
        int total = n;
        while(total && que.size())
        {
            int i = que.front();
            que.pop();
            total--;
            for(int j=0;j<graph[i].size();j++)
            {
                if (!--vec[graph[i][j]])
                {
                    que.push(graph[i][j]);
                }
            }
        }
        return total==0;
    }
};