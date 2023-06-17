class Solution {
public:
    bool canConstruct(const string& ransom, const string& magazine) {
        vector<int> arr(26,0);
        for (int i=0;i<magazine.length();i++)
        {
            ++arr[magazine[i]-97];
        }
        for(int i=0;i<ransom.length();i++)
        {
            if (--arr[ransom[i]-97]<0){return 0;}
        }
        
        return true;
    }
};
