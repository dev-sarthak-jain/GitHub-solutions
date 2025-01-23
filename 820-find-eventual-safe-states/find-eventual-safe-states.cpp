class Solution {
public:
    vector<int> answer;
    vector<bool> tip;
    bool func(vector<vector<int>>& graph, int x, vector<bool>& temp)
    {
        if (temp[x] == 1){return tip[x];}
        temp[x] = 1;
        int ans = 1;
        for(int i = 0;i<graph[x].size();i++)
        {
            ans = ans && func(graph,graph[x][i], temp);
        }
        if (ans){answer.push_back(x);}
        tip[x] = ans;
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> check(n,0);
        tip = vector<bool>(n,0);
        for(int i=0; i<n; i++)
        {
            if (!check[i]){func(graph, i, check);}
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};