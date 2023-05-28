class Solution {
public:
    vector<vector<int>> answer;
    vector<int> temp;

    void helper(int n,int k,int x)
    {
        if (k==0){answer.push_back(temp);return;}

        for(int i=x;i<n+1;i++)
        {
            temp.push_back(i);
            helper(n,k-1,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        helper(n,k,1);
        return answer;
    }
};