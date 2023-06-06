class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void recur(int k, int n, int x)
    {
        if (k<0){return;}
        if (n == 0)
        {
            if (k==0){ans.push_back(temp); return;}
            else
            {
                return;
            }
        }
        
        for(int i=x;i<=9;i++)
        {
            if (n-i>=0)
            {
                temp.push_back(i);
                recur(k-1,n-i,i+1);
                temp.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        recur(k,n,1);
        return ans;
    }
};