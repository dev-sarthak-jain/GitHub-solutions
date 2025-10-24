class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = numBottles;
        while(numBottles >= numExchange)
        {
            numBottles = numBottles - numExchange + 1;
            count += 1;
            numExchange+=1;
        }
        return count;
    }
};