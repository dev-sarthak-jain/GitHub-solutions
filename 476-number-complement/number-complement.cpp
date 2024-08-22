class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int tip = 0xFFFFFFFF;
        while(n!=0)
        {
            tip = tip << 1;
            n>>=1;
        }
        tip = ~tip;
        num = ~num;
        return tip&num;
    }
};