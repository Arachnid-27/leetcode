class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        bool neg = (dividend ^ divisor) >> 31;
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor < 0 ? -divisor : divisor;
        int count = 0;
        while (dividend + divisor <= 0) {
            int t1 = divisor;
            int t2 = 0;
            while (dividend + (t1 << 1) <= 0 && t2 < 30) {
                t1 <<= 1;
                ++t2;
            }
            dividend += t1;
            count += (1 << t2);
        }
        return neg ? -count : count;
    }
};
