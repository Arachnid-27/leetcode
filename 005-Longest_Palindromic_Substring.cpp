class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int l = 0, r = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < 2; ++j) {
                int k = 1 - j;
                while (k <= i && i + j + k < len && s[i - k] == s[i + j + k]) {
                    ++k;
                }
                if (2 * k - 1 + j > r - l + 1) {
                    l = i - k + 1;
                    r = i + j + k - 1;
                }
            }   
        }
        return s.substr(l, r - l + 1);
    }
};
