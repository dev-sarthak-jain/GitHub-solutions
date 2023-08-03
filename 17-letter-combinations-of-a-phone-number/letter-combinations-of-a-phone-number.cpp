class Solution {
public:
    vector<string> vec = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string temp = "";
    string digits;
    int n;

    void recur(int x)
    {
        if (x == n)
        {
            ans.push_back(temp);
            return;
        }

        string z = vec[digits[x] - '2'];
        for (int i = 0; i < z.length(); i++)
        {
            temp += z[i];
            recur(x + 1);
            temp = temp.substr(0, temp.length() - 1);
        }
    }

    vector<string> letterCombinations(string d) {
        n = d.length();
        if (n == 0) { return ans; }
        digits = d;
        recur(0);
        return ans;
    }
};
