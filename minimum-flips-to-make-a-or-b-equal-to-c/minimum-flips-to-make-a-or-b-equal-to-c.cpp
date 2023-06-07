class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a != 0 || b != 0) {
            bool f1 = a & 1;
            bool f2 = b & 1;
            bool f3 = c & 1;
            a >>= 1;
            b >>= 1;
            c >>= 1;

            if (f3) {
                if (!f1 && !f2) {
                    count++;
                }
            } else {
                if (f1 && f2) {
                    count += 2;
                } else if (f1 || f2) {
                    count++;
                }
            }
        }
        while (c != 0) {
            if (c & 1) {
                count++;
            }
            c >>= 1;
        }

        return count;
    }
};