class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0 && c; --i) {
            int s = digits[i] + c;
            digits[i] = s % 10;
            c = s / 10;
        }
        if (c) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
