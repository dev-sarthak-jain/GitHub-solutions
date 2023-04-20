class Solution {
public:
    void recur(vector<string>& ans , int n,int o, int c,string s)
    {
        if (n==o && n==c){ans.push_back(s);return;}

        if (o<n){recur(ans,n,o+1,c,s+'(');}
        if (c<o){recur(ans,n,o,c+1,s+')');}
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(ans,n,0,0,"");
        return ans;
    }
};