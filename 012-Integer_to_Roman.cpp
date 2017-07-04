class Solution {
public:
    string intToRoman(int num) {
        static array<int, 13> val = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        static array<char*, 13> sym = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string result;
        for (int i = 0; i < 13 && num; ++i) {
            while (num >= val[i]) {
                result.append(sym[i]);
                num -= val[i];
            }
        }
        return result;
    }
};
