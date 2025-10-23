class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        while(numBottles>=numExchange)
        {
            int quot = numBottles/numExchange;
            int rem = numBottles%numExchange;
            count += quot;
            numBottles = quot + rem;
        }
        return count;
    }
};