class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        size_t len = s.length();
        for (size_t i = 0; i < len; ++i) {
            switch (s[i]) {
                case 'I':
                    switch (s[i + 1]) {
                        case 'V':
                            result += 4;
                            ++i;
                            break;
                        case 'X':
                            result += 9;
                            ++i;
                            break;
                        default:
                            result += 1;
                            break;
                    }
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    switch (s[i + 1]) {
                        case 'L':
                            result += 40;
                            ++i;
                            break;
                        case 'C':
                            result += 90;
                            ++i;
                            break;
                        default:
                            result += 10;
                            break;
                    }
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    switch (s[i + 1]) {
                        case 'D':
                            result += 400;
                            ++i;
                            break;
                        case 'M':
                            result += 900;
                            ++i;
                            break;
                        default:
                            result += 100;
                            break;
                    }
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }
        return result;
    }
};
