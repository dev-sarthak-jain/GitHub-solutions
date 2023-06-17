class Solution {
public:
    bool isHappy(int n) {
        vector<int> vec = {0,1,4,9,16,25,36,49,64,81};
        unordered_set<int> s;
        int x;
        while(n!=1)
        {
            s.insert(n);
            x = n;
            n = 0;
            while(x!=0)
            {
                n  += vec[x%10];
                x/=10;
            }
            if (s.find(n)!=s.end()){return false;}
        }
        return true;
    }
};