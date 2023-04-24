class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(begin(stones), end(stones));
        while (q.size() > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if (x != y) q.push(abs(x - y));
        }
        return q.empty() ? 0 : q.top();
    }
};