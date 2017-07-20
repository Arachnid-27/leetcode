class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        vector<int> next(needle.length(), -1);
        makeNext(needle, next);
        int i = 0, j = 0;
        int n = haystack.length(), m = needle.length();
        while (i < n && j < m) {
            if (j == - 1 || haystack[i] == needle[j]) {
                ++i, ++j;
            } else {
                j = next[j];
            }
        }
        if (j == needle.length()) {
            return i - j;
        }
        return -1;
    }
private:
    void makeNext(string pattern, vector<int>& next) {
        int j = 0, k = -1;
        while (j < pattern.length() - 1) {
            if (k == -1 || pattern[k] == pattern[j]) {
                ++j, ++k;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
};
