class Solution {
public:
    unordered_set<string> sett;
    int n;

    bool recur(string s, int x, vector<int>& check) {
        if (n == x) {
            return true;
        }
        cout << x << endl;
        for (int i = x; i < n; i++) {
            if (sett.find(s.substr(x, i - x + 1)) != sett.end()) {
                if (check[i + 1] == 1) {
                    check[x] = true;
                    return true;
                }
                else if (check[i+1] == -1 && recur(s, i + 1, check))
                {
                    check[x] = true;
                    return true;
                }
            }
        }
        check[x] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& word) {
        n = s.length();
        for (int i = 0; i < word.size(); i++) {
            sett.insert(word[i]);
        }
        vector<int> check(n + 1, -1);
        return recur(s, 0, check);
    }
};