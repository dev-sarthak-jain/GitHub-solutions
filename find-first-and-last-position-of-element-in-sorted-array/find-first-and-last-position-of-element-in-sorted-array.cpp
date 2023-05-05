class Solution {
public:
    vector<int> ans = {-1,-1};
    vector<int> num;
    int tar;

    void binary(int s,int e)
    {
        if (s>e){return;}

        int mid  = (s+e)/2;
        if (num[mid] == tar)
        {
            int i = mid;
            while(i>=0 && num[i] == tar)
            {
                i--;
            }
            ans[0] = i+1;
            i = mid;
            while(i<num.size() && num[i] == tar)
            {
                i++;
            }
            ans[1] = i-1;
            return;
        }
        else if (num[mid] > tar){binary(s,mid-1);return;}
        else{binary(mid+1,e);return;}
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        num = nums;
        tar = target;
        binary(0,nums.size()-1);
        return ans;
    }
};