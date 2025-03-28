class Solution {
public:

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> temp = queries;
        sort(temp.begin(),temp.end());
        int n = temp.size();
        int x = grid.size(), y = grid[0].size();
        int score = 0;
        unordered_map<int,int> map;
        stack<pair<int,int>> cur;
        stack<pair<int,int>> fut;
        vector<int> ans(n);
        vector<vector<bool>> check(x,vector<bool>(y,0));
        cur.push({0,0});
        
        for(int i=0;i<n;i++)
        {
            if (map.count(temp[i])!=0){continue;}
            while(cur.size()!=0)
            {
                pair<int,int> next = cur.top();
                cur.pop();
                int a = next.first, b = next.second;
                if (a>=x || a<0 || b>=y || b<0){continue;}
                if (check[a][b]){continue;}
                if (grid[a][b]<temp[i])
                {
                    check[a][b] = 1;
                    score++;
                    cur.push({a+1,b});
                    cur.push({a,b+1});
                    cur.push({a-1,b});
                    cur.push({a,b-1});
                }
                else
                {
                    fut.push({a,b});
                }
            }
            map[temp[i]] = score;
            cur.swap(fut);
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = map[queries[i]];
        }
        return ans;
    }
};