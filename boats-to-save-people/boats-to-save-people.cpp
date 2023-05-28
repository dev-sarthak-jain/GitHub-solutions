class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans = 0;
        int temp = limit - people[0];
        while(j!=0 && people[j]>temp)
        {
            ans++;
            j--;
        }
        while(i<j)
        {
            if (people[i]+people[j]<=limit){ i++; j--;}
            else {j--;}
            ans++;
        }
        if (i==j)
        {
            return ans+1;
        }
        return ans;
    }
};