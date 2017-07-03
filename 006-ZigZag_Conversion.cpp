class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        auto len = s.length();
        auto step = 2 * numRows - 2;
        auto count = 0;
        string result(s);
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < len; j += step) {
                result[count++] = s[j];
                if (0 < i && i < numRows - 1) {
                    auto next = j + step - 2 * i;
                    if (next < len) {
                        result[count++] = s[next];
                    }
                }
            }
        }
        return result;
    }
};
