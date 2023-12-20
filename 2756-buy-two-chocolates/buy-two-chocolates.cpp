class Solution {
public:
    int buyChoco(vector<int>& money, int prices) {
        int x,y;
        if (money[0]>money[1]){
            x = money[1];y=money[0];
        }
        else
        {
            x = money[0];y=money[1];
        }
        for(int i=2;i<money.size();i++)
        {
            if (money[i]<=x){y=x;x=money[i];}
            else if (money[i]<y){y = money[i];}
        }
        return (prices-x-y>=0)?prices-x-y:prices;
    }
};