class Solution {
public:
    int myAtoi(string str) {
        auto len = str.length();
        size_t i = 0;
        int sign = 1;
        int result = 0;
        while (i < len && str[i] == ' ') {
            ++i;
        }
        if (i < len && str[i] == '-') {
            sign = -1;
            ++i;
        } else if (i < len && str[i] == '+') {
            ++i;
        }
        while (i < len) {
            char c = str[i++];
            if ('0' <= c && c <= '9') {
                int old = result;
                result = 10 * result + (c - '0');
                if (result / 10 != old) {
                    return sign > 0 ? INT_MAX : INT_MIN;
                }
            } else {
                break;
            }
        }
        return sign * result;
    }
};
