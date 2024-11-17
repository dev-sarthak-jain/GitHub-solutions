class Solution {
public:
    vector<string> ans;

    void func(int n, string temp, int o, int c)
    {
        if (n==o && n==c){ans.push_back(temp);}

        if (o<n){func(n,temp + '(',o+1,c);}
        if (c<n && c<o){func(n,temp + ')',o,c+1);}
        
    }

    vector<string> generateParenthesis(int n) {
        func(n,"",0,0);
        return ans;
    }
};