class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        int n = words.size();
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            int j=0, k=0;
            int m = words[i].size();
            while(k<m)
            {
                if (words[i][k] == sep){
                    string temp = words[i].substr(j,k-j);
                    j=k+1;
                    if (temp!=""){ans.push_back(temp);}

                }
                k++;
            }
            string temp = words[i].substr(j,k-j);
            if (temp!=""){ans.push_back(temp);}
        }
        return ans;
    }
};