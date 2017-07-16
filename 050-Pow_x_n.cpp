class Solution {
public:
    double myPow(double x, int n) {
        double s = 1, t = n < 0 ? (1 / x) : x;
        while (n) {
            if (n % 2) {
                s *= t;
            }
            t *= t;
            n /= 2;
        }
        return s;
    }
};
