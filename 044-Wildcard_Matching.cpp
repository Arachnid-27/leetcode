class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, ks = -1, kp = -1;
        while (i < s.length()) {
            if (j < p.length() && p[j] == '*') {
                ks = i;
                kp = ++j;
            } else if (j < p.length() && (p[j] == '?' || p[j] == s[i])) {
                ++i;
                ++j;
            } else if (ks != -1) {
                i = ++ks;
                j = kp;
            } else {
                return false;
            }
        }
        while (j < p.length() && p[j] == '*') {
            ++j;
        }
        return j == p.length();
    }
};
