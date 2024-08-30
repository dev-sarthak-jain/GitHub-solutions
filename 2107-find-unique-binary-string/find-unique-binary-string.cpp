class Solution {
public:
    unordered_set<string> set;
    
    string func(string& arr, int n, int x)
    {
        if (n==x)
        {
            if (set.find(arr)==set.end())
            {
                return arr;
            }
            else
            {
                return "";
            }
        }
        arr += "0";
        string ans = func(arr, n,x+1);
        if (ans != ""){return ans;}
        arr.erase(x);
        arr += "1";
        ans = func(arr, n,x+1);
        if (ans != ""){return ans;}
        arr.erase(x);
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n  = nums.size();
        int m = nums[0].size();
        string arr;
        for(int i=0;i<n;i++)
        {
            set.insert(nums[i]);
        }
        return func(arr,m,0);
        
    }
};