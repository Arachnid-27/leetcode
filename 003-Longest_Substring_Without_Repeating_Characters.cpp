class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int i, pos;
        int result = 0, beg = 0;
        int len = s.length();
        for (i = 0; i < len; ++i) {
            pos = s[i];
            if (hash[pos] >= beg) {
                result = max(result, i - beg);
                beg = hash[pos] + 1;
            }
            hash[pos] = i;
        }
        return max(result, i - beg);
    }
};
