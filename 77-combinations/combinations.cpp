class Solution {
public:
    vector<vector<int>> answer;
    vector<int> temp;

    void recur(int n, int k, int x)
    {
        if (k==0){answer.push_back(temp);}

        for(int i=x;i<n+1;i++)
        {
            temp.push_back(i);
            recur(n,k-1,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        recur(n,k,1);
        return answer;
    }
};