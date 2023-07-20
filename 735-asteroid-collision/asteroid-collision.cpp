class Solution {
public:
    vector<int> ans;
    stack<int> s;

    void recur()
    {
        if (s.size() != 0)
        {
            int x = s.top();
            s.pop();
            recur();
            ans.push_back(x);
        }
        else
        {
            return;
        }
    }

    vector<int> asteroidCollision(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]<0)
            {
                bool flag = 1;
                while(s.size()!=0)
                {
                    if (s.top() > -1*nums[i]){flag = 0;break;}
                    else if(s.top() == -1*nums[i]){s.pop();flag = 0;break;}
                    else{s.pop();}
                }
                if (flag){ans.push_back(nums[i]);}
            }
            else
            {
                s.push(nums[i]);
            }
        }
        recur();
        return ans;
    }
};